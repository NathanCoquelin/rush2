##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## This will be used to compile and clean files
##

.SECONDEXPANSION:
PROGRAM			:=	../rush2
TEST_PROGRAM		:=	../tests_rush2

$(PROGRAM)_SRCS		:=	../count_letters.c	\
				../sort_offsets.c	\
				../main.c

$(TEST_PROGRAM)_SRCS	:=	../tests/test_print_result.c	\
				../tests/test_rush2_main.c	\
				../count_letters.c		\
				../sort_offsets.c

$(PROGRAM)_OBJS		:=	$($(PROGRAM)_SRCS:.c=.o)
$(TEST_PROGRAM)_OBJS	:=	$($(TEST_PROGRAM)_SRCS:.c=.o)
LIBS			:=	my
LIB_DIRS		:=	../lib/my/
INCLUDE_DIRS		:=	../include/ ../
CC			:=	gcc
CFLAGS			:=	$(patsubst %,-I%,$(INCLUDE_DIRS))
LDFLAGS			:=	$(patsubst %,-l%,$(LIBS))\
				$(patsubst %,-L%,$(LIB_DIRS))
$(TEST_PROGRAM)_CFLAGS	:=	-g --coverage
$(TEST_PROGRAM)_LDFLAGS	:=	-lcriterion

all:				$(PROGRAM)

$(PROGRAM) $(TEST_PROGRAM):	$$($$@_OBJS)
	$(CC) -o $@ $($@_CFLAGS) $(CFLAGS) $($@_OBJS) $(LDFLAGS) $($@_LDFLAGS)

tests_run:			$(TEST_PROGRAM)
	$(TEST_PROGRAM)
	cd ..
	gcovr --exclude tests/
clean:
	@rm -f $($(PROGRAM)_OBJS)
	@rm -f $($(TEST_PROGRAM)_OBJS)
	@rm -f $(wildcard *~)
	@rm -f $(wildcard \#*\#)
	@rm -f $(wildcard .\#*)
	@rm -f $(wildcard vgcore.*)
	@rm -f $(wildcard *.gcda)
	@rm -f $(wildcard *.gcno)

fclean:			clean
	@rm -f $(PROGRAM) $(TEST_PROGRAM)

re:				fclean all

re_tests:			fclean tests_run

.PHONY:			all tests_run clean fclean re
