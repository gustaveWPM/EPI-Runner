/*
** EPITECH PROJECT, 2021
** errors_vocab.h
** File description:
** Errors Msg
*/

#ifndef ERRORS_MSG_H
#define ERRORS_MSG_H
static const struct {
    char *EMPTY_MAP_FILE;
    char *FILE_IS_UNREADABLE;
    char *FORBIDDEN_MAP_CHARS;
    char *INVALID_HEIGHT;
} ERRORS_VOCAB = {
    "Erreur:\n\tLe fichier est vide.\n",
    "Erreur:\n\tImpossible d'ouvrir le fichier.\n",
    "Erreur:\n\tLa map contient des caracteres inconnus.\n",
    "Erreur:\n\tUne map ne peut pas faire plus de 13 tiles de haut.\n"
};
#endif
