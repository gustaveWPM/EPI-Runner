##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## All-inclusive Makefile for MyRunner project
##

.PHONY: all
.PHONY: build_lib
.PHONY: clean
.PHONY: fclean
.PHONY: re


EXECUTABLE_NAME			=	my_runner
LIB_NAME			=	libmy.a


LIB_PATH			=	lib
MY_LIB_PATH			=	lib/my


INC_LIB				=	-L. -lmy
CFLAGS	 			=	-I./modules/ -I./modules/constants/ -I./modules/dependencies/		\
					-I./modules/prototypes -I./lib/my/modules/
CSFML_FLAGS			=	-l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio
C_COMPILER			=	gcc


SRC_ROOT_FOLDER			=	src
DRAWERS_FOLDER			=	$(SRC_ROOT_FOLDER)/drawers
ETC_FOLDER			=	$(SRC_ROOT_FOLDER)/etc
GAMEPLAY_FOLDER			=	$(SRC_ROOT_FOLDER)/gameplay
MANAGERS_FOLDER			=	$(SRC_ROOT_FOLDER)/managers
MEMORY_FOLDER			=	$(SRC_ROOT_FOLDER)/memory
PARSER_FOLDER			=	$(SRC_ROOT_FOLDER)/parser


RM_OBJ				=	@rm -f $(ALL_PROG_OBJ) && rm -f $(LIB_OBJ)
RM_LIB				=	@rm -f $(LIB_NAME)


LIB_SRC				=	$(MY_LIB_PATH)/math.c							\
					$(MY_LIB_PATH)/my_putchar.c						\
					$(MY_LIB_PATH)/my_puterr_nb.c						\
					$(MY_LIB_PATH)/my_putnbr.c						\
					$(MY_LIB_PATH)/my_str_funs.c

MAIN_SRC			=	$(SRC_ROOT_FOLDER)/main.c

DRAWERS_SRC			=	$(DRAWERS_FOLDER)/drawers.c						\
					$(DRAWERS_FOLDER)/draw_game_spriteset.c					\
					$(DRAWERS_FOLDER)/draw_fogs.c						\
					$(DRAWERS_FOLDER)/draw_parallaxes.c					\
					$(DRAWERS_FOLDER)/update.c

ETC_SRC				=	$(ETC_FOLDER)/game_initializers.c					\
					$(ETC_FOLDER)/game_player_initializers.c				\
					$(ETC_FOLDER)/game_loader.c						\
					$(ETC_FOLDER)/game_window.c						\
					$(ETC_FOLDER)/map_infos.c						\
					$(ETC_FOLDER)/tiles_passabilities.c					\
					$(ETC_FOLDER)/set_path.c						\
					$(ETC_FOLDER)/load_map.c

GAMEPLAY_SRC			=	$(GAMEPLAY_FOLDER)/check_player_x.c					\
					$(GAMEPLAY_FOLDER)/check_y_axis.c					\
					$(GAMEPLAY_FOLDER)/game_loop.c						\
					$(GAMEPLAY_FOLDER)/gameplay.c						\
					$(GAMEPLAY_FOLDER)/movements.c						\
					$(GAMEPLAY_FOLDER)/game_restart.c					\
					$(GAMEPLAY_FOLDER)/physics_engine.c

MANAGERS_SRC			=	$(MANAGERS_FOLDER)/sound_manager.c

MEMORY_SRC			=	$(MEMORY_FOLDER)/allocations.c						\
					$(MEMORY_FOLDER)/free.c							\
					$(MEMORY_FOLDER)/free_tileset.c						\
					$(MEMORY_FOLDER)/terminate.c

PARSER_SRC			=	$(PARSER_FOLDER)/map_checker.c


LIB_OBJ				=	$(LIB_SRC:.c=.o)

MAIN_OBJ			=	$(MAIN_SRC:.c=.o)
DRAWERS_OBJ			=	$(DRAWERS_SRC:.c=.o)
ETC_OBJ				=	$(ETC_SRC:.c=.o)
GAMEPLAY_OBJ			=	$(GAMEPLAY_SRC:.c=.o)
MANAGERS_OBJ			=	$(MANAGERS_SRC:.c=.o)
MEMORY_OBJ			=	$(MEMORY_SRC:.c=.o)
PARSER_OBJ			=	$(PARSER_SRC:.c=.o)

ALL_PROG_OBJ			=	$(MAIN_OBJ) $(DRAWERS_OBJ) $(ETC_OBJ)					\
					$(GAMEPLAY_OBJ)	$(MANAGERS_OBJ) $(MEMORY_OBJ) $(PARSER_OBJ)


BUILD_LIB			=	ar rc $(LIB_NAME) $(LIB_OBJ)
BUILD_PROG			=	$(C_COMPILER) $(CFLAGS) 						\
					-o $(EXECUTABLE_NAME) $(ALL_PROG_OBJ) $(INC_LIB) $(CSFML_FLAGS)


$(EXECUTABLE_NAME):	$(LIB_NAME) $(ALL_PROG_OBJ)
				@$(BUILD_PROG) > /dev/null

all:			$(EXECUTABLE_NAME)

$(LIB_NAME):		$(LIB_OBJ)
				@$(BUILD_LIB) > /dev/null

lib:			$(LIB_NAME)

clean:
				$(RM_OBJ)
				$(RM_LIB)

fclean: 		clean
				@rm -rf $(EXECUTABLE_NAME)

re:			fclean all
