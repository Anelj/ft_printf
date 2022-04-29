NAME = libftprintf.a
DIR_OBJ = obj
LIST = ft_printf.c ft_itoabase.c ft_optionshandler.c ft_putstr.c
OBJ = $(addprefix $(DIR_OBJ)/, $(LIST:.c=.o))

all : $(NAME)

$(NAME) : ./libft/libft.a $(OBJ)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

./libft/libft.a : libft

libft :
	$(MAKE) bonus -C ./libft
	
$(DIR_OBJ)/%.o : %.c ./ft_printf.h
	mkdir -p $(DIR_OBJ)
	gcc -Wall -Werror -Wextra -c $< -o $@

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(DIR_OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re libft
