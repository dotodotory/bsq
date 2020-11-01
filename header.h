/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiykim <jiykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:24:08 by jiykim            #+#    #+#             */
/*   Updated: 2020/11/01 20:48:07 by jiykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_HEAD
#define H_HEAD
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFF_SIZE 1024

int g_row;
int g_col;
char c[3];
extern int ret[3];

char *ft_strncpy(char *dest, char *src, int size);
int is_error(int nb);
void ft_free_map(int **ptr);
int ft_atoi(char *str, int size);
int ft_first_line(char *str);
int ft_read_file(int fd, char *buf);
int is_in_string(char *str, char c);
int handle_map_error(char *str);
int *ft_str_to_int(int *list, char *str, int size);
int ft_read_file2(int **map, int fd2, char *buf2);
int handle_error(int fd, char *buf);
int ft_open_file(char *file, char *buf);
int ft_open_file2(char *file2, char *buf2);
int *ft_calloc(int *addr, int size);
int minimum(int i, int j, int **map);
void chk(int **map);
void print_map(int **map, char *moji);


#endif
