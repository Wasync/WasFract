NAME = Fractal

FLAGS =
INCLUDES = -I includes/ -I includes/includes_SDL2/

LIB_DIR = libs/
LIBRARIES = -l SDL2 -l SDL2_image -l SDL2_ttf -lm
STATIC_LIB = -L -l $(LIB_DIR)libMT.a 

LERP_DIR = Lerp/
GRADIENT_DIR = Gradient/
SRCS_DIR = srcs/
BIN_DIR = bin/
SDLX_DIR = SDLX/
MT_DIR = MT/


GRADIENT_NAMES =		\
	gradient			\
	utils				\

LERP_NAMES=				\
	lerp				\

MT_NAMES=				\
	MT_matrix			\
	MT_v2				\
	MT_v3				\
	MT					\

SDLX_NAMES = 			\
	SDLX_anim			\
	SDLX_init			\
	SDLX_input			\
	SDLX_render			\
	SDLX				\


SRCS_NAMES =			\
	colors				\
	fractal				\
	input_handler		\
	render				\
	main 				\

C_FILES =				\
	$(addprefix $(LERP_DIR), $(LERP_NAMES))		\
	$(addprefix $(GRADIENT_DIR), $(GRADIENT_NAMES))	\
	$(addprefix $(SDLX_DIR), $(SDLX_NAMES))	\
	$(addprefix $(MT_DIR), $(MT_NAMES))	\
	$(SRCS_NAMES) 		\

SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR), $(C_FILES)))
OBJS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

all: $(NAME)

wasm: 
	emcc $(INCLUDES) -o $(NAME) $(SRCS) -s USE_SDL=2 -sALLOW_MEMORY_GROWTH -o cats.html 

$(NAME): $(BIN_DIR) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBRARIES)  $(STATIC_LIB)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)%.o: %.c
	mkdir -p $(BIN_DIR)$(dir $<)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

run: re clean
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all