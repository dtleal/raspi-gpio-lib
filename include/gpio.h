#ifndef GPIO_H
#define GPIO_H

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>

#define OK          0
#define ERROR       -1
#define HIGH        1
#define LOW         0
#define GPIO_DIR    "/sys/class/gpio/"
#define GPIO_DIR_SIZE sizeof(GPIO_DIR)

/* Estrutura principal */
struct gpio_st {
    char pin[4];
    char direction[3];
    FILE *file;
};

/* Funcoes */
char *sys_class_path(char opt, struct gpio_st *app_st);
int export_gpio(struct gpio_st *app_st);
int direction_gpio(struct gpio_st *app_st);
int set_gpio_pin_value(char *value, struct gpio_st *app_st);
int get_gpio_pin_value(struct gpio_st *app_st);
int unexport_gpio(struct gpio_st *app_st);

#endif
