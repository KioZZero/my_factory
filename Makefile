CXX             =   g++

PROJECT_DIR     =   my_factory_project

INCLUDE_DIR     =   $(PROJECT_DIR)/include

SOURCE_DIR      =   $(PROJECT_DIR)/source

INCLUDE_DIRS    =   $(INCLUDE_DIR) \
					$(INCLUDE_DIR)/Game/Character \
					$(INCLUDE_DIR)/Game/Component \
					$(INCLUDE_DIR)/SFML \
					$(INCLUDE_DIR)/Log \
					$(INCLUDE_DIR)/Core \
					$(INCLUDE_DIR)/Utils \

SOURCES_FILES   =   $(SOURCE_DIR)/main.cpp \
					$(SOURCE_DIR)/conditions.cpp \
					$(SOURCE_DIR)/Core/Core.cpp \
					$(SOURCE_DIR)/Core/Parser.cpp \
					$(SOURCE_DIR)/Core/Preloader.cpp \
					$(SOURCE_DIR)/Core/Server.cpp \
					$(SOURCE_DIR)/SFML/SFMLManager.cpp \
					$(SOURCE_DIR)/SFML/SimplifiedSFML.cpp \
					$(SOURCE_DIR)/Game/Character/ACharacter.cpp \
					$(SOURCE_DIR)/Game/Character/CCharacter.cpp \
					$(SOURCE_DIR)/Game/Character/OtherCharacter.cpp \
					$(SOURCE_DIR)/Game/Character/PlayerCharacter.cpp \
					$(SOURCE_DIR)/Log/LogManager.cpp \

NAME            =   my_factory

OBJS            =   $(SOURCES_FILES:.cpp=.o)

CXXFLAGS        =   -std=c++20 -Wall -Wextra $(addprefix -I,$(INCLUDE_DIRS))

LDFLAGS         =   -lconfig++ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

all: $(NAME)

$(NAME):    $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o:    %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re