# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 23:45:00 by zcadinot          #+#    #+#              #
#    Updated: 2025/11/08 00:22:19 by zcadinot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = randint.a
SRC_DIR     = src
OBJ_DIR     = obj
TEST_DIR    = test

SRC         = $(SRC_DIR)/ft_randint.c
OBJ         = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I$(SRC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "✅  Library built: $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🧩  Compiled $<"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

test: $(NAME)
	@$(CC) $(CFLAGS) $(TEST_DIR)/main.c $(NAME) -o test.out
	@echo "🚀  Running test..."
	@./test.out

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧹  Object files cleaned"

fclean: clean
	@rm -f $(NAME) test.out
	@echo "🧽  Full clean done"

re: fclean all

.PHONY: all clean fclean re test
