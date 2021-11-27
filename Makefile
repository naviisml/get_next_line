NAME = program

AR = @ar
AR_FLAGS = -rcs

COMPILER = @gcc
COMPILER_FLAGS = -Wall -Werror -Wextra

# Configuration

# Source Files...
SOURCE_FOLDER	=	./srcs
SOURCE_FILES	=	ft_example.c

# Object Files...
EXTRA_FOLDERS	=	$(SOURCE_FOLDER)
OBJECT_FOLDER	=	./objects
OBJECT_FILES	=	$(addprefix $(OBJECT_FOLDER)/, $(addprefix $(SOURCE_FOLDER)/, $(SOURCE_FILES:.c=.o)))

.PHONY =  $(NAME) all clean fclean re dev

# Compile the .c files to .o files...
$(OBJECT_FOLDER)/%.o: %.c
	@mkdir -p $(OBJECT_FOLDER) $(addprefix $(OBJECT_FOLDER)/, $(dir $<))
	@echo "Compiling \t$(notdir $<) (100%)"
	@$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

# Compile the program...
$(NAME): $(OBJECT_FILES)
	@echo "Building \t$(NAME)... (100%)"
	$(COMPILER) $(COMPILER_FLAGS) $(OBJECT_FILES) -o $(NAME)

all: $(NAME)

# Remove the `object` folder and files...
clean:
	@rm -rf $(OBJECT_FILES) $(OBJECT_FOLDER)

# Remove the `object` and `build` folder and files...
fclean: clean
	@rm -rf $(NAME)

# Clean the program up and re-compile it...
re: fclean all

# Re-compile the program and run the script...
dev: re
	@echo "Running \t$(NAME)..."
	@./$(NAME)
