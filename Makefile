CXX				=	g++

PROJECT_DIR		=	my_factory_project

INCLUDE_DIR		=	$(PROJECT_DIR)/include

SOURCE_DIR		=	$(PROJECT_DIR)/source

INCLUDE_DIRS	=	$(INCLUDE_DIR) \
					$(INCLUDE_DIR)/Character \
					$(INCLUDE_DIR)/Core \
					$(INCLUDE_DIR)/Utils \

SOURCES_FILES	=	$(SOURCE_DIR)/main.cpp \
					$(SOURCE_DIR)/conditions.cpp \
					$(SOURCE_DIR)/Character/PlayerCharacter.cpp \
					$(SOURCE_DIR)/Character/OtherCharacter.cpp \
					$(SOURCE_DIR)/Character/ACharacter.cpp \
					$(SOURCE_DIR)/Character/CCharacter.cpp \
					$(SOURCE_DIR)/Core.cpp \


# Object files

NAME			=	my_factory

OBJS		=	$(SOURCES_FILES:.cpp=.o)

CXXFLAGS	=	-std=c++20 -Wall -Wextra $(addprefix -I,$(INCLUDE_DIRS))

all: $(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(OBJS) -o $(NAME) -lconfig++

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re%     