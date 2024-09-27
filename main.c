#include "get_next_line.h"
#include <fcntl.h> // Para la función open()
#include <stdio.h> // Para la función printf()

int	main(void)
{
	char	*line;

	int fd = open("archivo_de_prueba.txt", O_RDONLY);
		// Abre un archivo en modo lectura
	if (fd == -1)
	{
		perror("Error abriendo archivo");
		return (1);
	}
    while ((line = get_next_line(fd)) != NULL)  // Llama a get_next_line en un bucle
    {
        printf("%s", line);  // Imprime la línea leída
        free(line);          // Libera la memoria asignada por get_next_line
    }

    close(fd);  // Cierra el archivo
    return 0;
}

/*cc -Wall -Werror -Wextra -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c
main.c -o gnl_test
./gnl_test*/
