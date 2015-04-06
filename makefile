NAME = pokerom

CXX_SOURCES = \
\
src/main.vala \

CXX = valac

CXX_PACKAGES = --pkg sdl --pkg sdl-gfx -X -lSDL_gfx -X -I/usr/include/SDL --Xcc=-I/usr/include/SDL

CXX_EXTRA = -X -lm
CXX_FLAGS = -X -Wall

CXX_LINES=`( find src -name '*.vala' -print0 | xargs -0 cat ) | wc -l`

default: build

build: $(CXX_SOURCES)
	
	@echo "Building..."
	@$(CXX) -o $(NAME) $(CXX_FLAGS) $(CXX_EXTRA) $(CXX_PACKAGES) $(CXX_SOURCES)
	@echo "Built."
	@echo "Info: There are $(CXX_LINES) lines of Vala code."

run: $(NAME)
	
	@echo "Running..."
	@./$(NAME)

help:
	
	@echo "To compile, run 'make build'"
	@echo "To install, run 'sudo make install'"
