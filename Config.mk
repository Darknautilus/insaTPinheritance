# =====
# INSA Lyon, Département Informatique
# TP C++ 3IF :  Héritage et polymorphisme
# Auteur : B3229
# =====

MODE=RELEASE
CC=g++
CFLAGS=-std=c++0x
LDFLAGS=
PATHEXEC=bin/
EXEC=inherit
TARGET=$(addprefix $(PATHEXEC), $(EXEC))

ifeq ($(MODE),DEBUG)
	CFLAGS:=$(CFLAGS) -g
endif
