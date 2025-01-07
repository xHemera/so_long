/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:26:55 by hemera            #+#    #+#             */
/*   Updated: 2025/01/07 19:34:51 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define BUFFER_SIZE 32  // Taille du buffer pour lire les données

// Fonction pour lire une ligne du fichier
int get_next_line(int fd, char **line) {
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;
    int i = 0;

    if (!line || fd < 0)
        return (-1);

    *line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!*line)
        return (-1);

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytes_read] = '\0';  // Assurez-vous que la chaîne est terminée par '\0'

        // Recherche du saut de ligne dans le buffer
        while (buffer[i] != '\0' && buffer[i] != '\n') {
            (*line)[i] = buffer[i];
            i++;
        }

        (*line)[i] = '\0';  // Ajoute un caractère de fin de chaîne

        if (buffer[i] == '\n') {
            // Si on rencontre un saut de ligne, on arrête la lecture et on retourne
            return (1);
        }

        if (bytes_read < BUFFER_SIZE)
            break;  // Fin du fichier atteint
    }

    if (bytes_read == 0 && i == 0) {
        // Si rien n'a été lu, c'est la fin du fichier
        free(*line);
        *line = NULL;
        return (0);
    }

    return (1);
}
