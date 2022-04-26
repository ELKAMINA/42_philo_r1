/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminaelk <aminaelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:17:59 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/19 17:34:54 by aminaelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_glob_info
{
	int					nb_philos;
	int					all_forks;
	pthread_mutex_t		is_alive;
	pthread_mutex_t		msg;
	pthread_mutex_t		start;
	pthread_mutex_t		timest;
	int					is_dead;
	int					nb_of_meals;
	time_t				start_diner;
	time_t				timestamp;
	time_t				time_to_sleep;
	time_t				time_to_eat;
	time_t				time_to_die;
}	t_glob_info;

typedef struct s_philo_mode
{
	char	eating;
	char	thinking;
	char	sleeping;
	char	dying;
}	t_philo_mode;

typedef struct s_philo
{
	int				id;
	int				nb_fork;
	pthread_mutex_t	p_fork;
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;
	int				meals_eaten;
	time_t			last_meal;
	time_t			got_fork;
	time_t			start_eating;
	time_t			finish_eating;
	time_t			is_sleeping;
	time_t			is_thinking;
	time_t			died;
	pthread_t		th;
	pthread_t		check;
	struct s_philo	*previous;
	struct s_philo	*next;
	t_glob_info		*glob_infos;
}	t_philo;

int			check_char(char *argv[]);
t_glob_info	*get_info_args(int argc, char *argv[]);
long		ft_atol(const char *str);
t_philo		*ft_lstnew(t_glob_info *glb_info);
void		ft_lstadd_back(t_philo **alst, t_philo *node);
t_philo		*ft_lstlast(t_philo *lst);
int			ft_lstsize(t_philo *lst);
void		ft_lstadd_front(t_philo **alst, t_philo *node);
void		ft_lstclear(t_philo **lst);
void		ft_lstdelone(t_philo *lst, void (*del)(void*));
int			ft_strlen(char *str);
void		ft_exit(t_philo *list);
t_glob_info	*init_globInf(t_glob_info *glb_info);
t_philo		*create_ll(t_glob_info *infos);
void		create_all_philos(t_philo *philo_fi, t_philo *philo_sec,
				t_glob_info *infos);
void		circularing(t_philo **a);
void		incr_id_fork(t_philo **philo_fi, t_glob_info *infos);
void		print_lst(t_philo **phi);
void		dining_philos(t_philo **philo_fi, t_glob_info *infos);
time_t		convert_toms(void);
int			my_usleep(t_philo *philo, time_t t, int fork_use);
int			my_usleep_to_check(time_t t);
time_t		countdown(time_t time, t_philo *copy);
int			check_dead(t_philo *philo, time_t last_meal, time_t time_to_die);
void		destroy_mutexes(t_philo *philo);
void		freeing_philo(t_philo *philo);
void		ft_errarg(void);
void		decircularing(t_philo **a, int size);
int			take_fork_one(t_philo *philo);
int			take_fork_two(t_philo *philo);
void		func_living(t_philo *copy);
int			create_th(t_philo *copy, t_glob_info *infos);
void		join_th(t_philo *copy, t_glob_info *infos);
void		message_tosend(char *str, time_t *timestamp, t_philo *philo);
void		dying_philo(t_philo *philo);
int			check_dead(t_philo *philo, time_t last_meal, time_t time_to_die);
void 		creating_threads(t_philo *copy, t_glob_info *infos);
char		check_errors(t_glob_info *infos);
time_t		countdown_death(time_t time);
void		think_sleep(t_philo *copy);
void		timing(t_philo *copy);

#endif
