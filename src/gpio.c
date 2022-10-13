#include "gpio.h"

char *sys_class_path(char opt, struct gpio_st *app_st)
{
    char *path=malloc(sizeof(char));

    if (path == NULL)
        return NULL; 

    memset(path, 0, sizeof(path));

    switch(opt) {
        case 'e':
            path = realloc(path, GPIO_DIR_SIZE + 7);
            sprintf(path, "%sexport", GPIO_DIR);
            break;

        case 'd':
            path = realloc(path, GPIO_DIR_SIZE + 18);
            sprintf(path, "%sgpio%s/direction", GPIO_DIR, app_st->pin);
            break;

        case 's':
            path = realloc(path, GPIO_DIR_SIZE + 14);
            sprintf(path, "%sgpio%s/value", GPIO_DIR, app_st->pin);
            break;

        case 'v':
            path = realloc(path, GPIO_DIR_SIZE + 14);
            sprintf(path, "%sgpio%s/value", GPIO_DIR, app_st->pin);
            break;

        case 'u': 
            path = realloc(path, GPIO_DIR_SIZE + 10);
            sprintf(path, "%sunexport", GPIO_DIR);
            break;

        default: 
            path = realloc(path, GPIO_DIR_SIZE + 1); 
            sprintf(path, "%s", GPIO_DIR);
            break;
    }

    return path;
}

int export_gpio(struct gpio_st *app_st)
{
    int ret=0;
 
    app_st->file = NULL;
    app_st->file = fopen(sys_class_path('e', app_st), "w");
  
    if (app_st->file == NULL)
        return ERROR;

    ret = fputs(app_st->pin, app_st->file);

    fclose(app_st->file);

    return ret;
}

int direction_gpio(struct gpio_st *app_st)
{
    int ret=0;
    
    app_st->file = NULL;
    app_st->file = fopen(sys_class_path('d', app_st), "w");

    if (app_st->file == NULL)
        return ERROR;

    ret = fputs(app_st->direction, app_st->file);

    fclose(app_st->file);

    return ret;
}

int set_gpio_pin_value(char *value, struct gpio_st *app_st)    
{
    int ret=0;

    if (!strcmp(app_st->direction, "in"))
            return -1001;

    app_st->file = fopen(sys_class_path('s', app_st), "w");

    if (app_st->file == NULL)
        return ERROR;

    ret = fputs(value, app_st->file);

    fclose(app_st->file);

    return ret;
}

int get_gpio_pin_value(struct gpio_st *app_st)
{
    int ret;
    
    app_st->file = fopen(sys_class_path('v', app_st), "r");
    
    fscanf(app_st->file, "%d", &ret);    
    fclose(app_st->file);
    
    return ret;
}


int unexport_gpio(struct gpio_st *app_st)
{
    int ret=0;
 
    app_st->file = NULL;
    app_st->file = fopen(sys_class_path('u', app_st), "w");
  
    if (app_st->file == NULL)
        return ERROR;

    ret = fputs(app_st->pin, app_st->file);

    fclose(app_st->file);

    return ret;
}
