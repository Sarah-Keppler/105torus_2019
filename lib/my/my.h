/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Useful functions of lib c.
*/

#ifndef MY_H_
#define MY_H_

//Display
void my_putchar(char);
void my_putstr(char const *);
void my_put_nbr(int);
void display_digits(int);

//String
int my_strlen(char const *);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int match(char *, char const *, int);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);

//Calculation
int my_compute_power_rec(int, int);

//Others functions
int my_getnbr(char const *);
int my_str_character(char const *);
int my_strlen_per(char const *, char);
void my_isneg(int);
void my_swap(int *, int *);
void my_swap_char(char *, char *);
int my_str_isint_float(char const *);
int my_str_isnum(char const *);

#endif /* MY_H_ */
