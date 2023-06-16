#!/bin/bash

echo "Vérification de la norminette pour le projet FRACT-OL"
echo "-------------------"

# Fonction pour vérifier la norme d'un fichier avec la norminette
check_norminette() {
    file="$1"
    norminette "$file" | grep -E "Error|Warning" 2>&1
}

# Couleurs pour l'affichage
GREEN='\033[32m'
RED='\033[31m'
NC='\033[0m' # Couleur par défaut

# Variable pour suivre l'état d'erreur
has_error=false

# Parcourir tous les fichiers .c et .h
for file in $(find . -type f \( -name "*.c" -o -name "*.h" \) -not -path "./minilibx-linux/*"); do
    output=$(check_norminette "$file")

    if [[ -n $output ]]; then
        echo -e "${RED}Erreur:${NC} Fichier : $file"
        echo "$output"
		echo -------------------
        has_error=true
    fi
done

# Affichage des autres fichiers .c et .h vérifiés
echo "fichiers .h et .c vérifiés :"
find . -type f \( -name "*.c" -o -name "*.h" \) -not -path "./minilibx-linux/*" -not -path "./libft/*"
echo "./libft/*"

# Affichage final en fonction de l'état d'erreur
if [[ $has_error = false ]]; then
    echo -e "${GREEN}OK${NC}"
else
    echo -e "${RED}KO${NC}"
fi