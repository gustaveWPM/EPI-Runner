/*
** EPITECH PROJECT, 2021
** vocab.h
** File description:
** Vocab
*/

#ifndef VOCAB_H
#define VOCAB_H
static const struct {
    char *USAGE;
} VOCAB = {
    "\
Finite runner created with CSFML.\n\n\
USAGE\n\
\t./my_runner map.txt\n\n\n\
OPTIONS\n\
\t-h (alias: --help)\tprint the usage and quit.\n\n\
USER INTERACTIONS\n\
\tSPACE_KEY\tjump.\n\
\tESCAPE_KEY\ttoggle pause ON.\n\
\tMOUSE_CLICK\ttoggle pause OFF.\n\
\tF12\t\trestart game.\n"
};
#endif
