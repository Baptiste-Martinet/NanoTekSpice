##
## EPITECH PROJECT, 2019
## makefile
## File description:
## g++
##

NAME	= nanotekspice

CC	= g++

RM	= rm -f

SRCS	= 	./AComponent.cpp \
	  		./Pin.cpp \
			./TriStateGates.cpp \
			./components/DualFlipFlop.cpp	\
			./components/EightBitShiftRegister.cpp	\
			./components/FourAndGates.cpp 	\
			./components/FourBitAdder.cpp	\
			./components/FourBitDecoder.cpp	\
			./components/FourNandGates.cpp 	\
			./components/FourNorGates.cpp	\
			./components/FourOrGates.cpp	\
			./components/FourXorGates.cpp	\
			./components/Ram.cpp	\
			./components/Rom.cpp	\
			./components/SixInverterGates.cpp	\
			./components/TenBitJohnsonDecade.cpp	\
			./components/TwelveBitCounter.cpp	\
			./components/Input.cpp \
			./components/Output.cpp \
			./components/True.cpp \
			./components/False.cpp \
			./components/Circuit.cpp \
			./components/Clock.cpp \
			./components/Terminal.cpp \
			./SimulationLoop.cpp \
			./Factory.cpp \
			./Error.cpp \
			./main.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
