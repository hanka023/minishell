#include <signal.h>
#include <errno.h>
#include <string.h>

#include "minishell.h"

void	sighandler(int sig)
{
	if (sig == SIGINT)
	{
		// 1. Vrátíme chování signálu na default (ukončení)
		signal(SIGINT, SIG_DFL);
		// 2. Pošleme SIGINT sami sobě (nebo svému procesu)
		// kill(getpid(), SIGINT);
		// Alternativně stačí jen:
		raise(SIGINT);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	int		j;

	j = 0;
	while (1)
	{
		if (signal(SIGINT, sighandler) == SIG_ERR)
		{
			perror ("signal");
			return (1);
		}
		while (j < 10) //odpocitavani casu 
		{
			//printf ("%d\n", j);
			++j;
			sleep (2);
		}
	}
	return (0);
}
