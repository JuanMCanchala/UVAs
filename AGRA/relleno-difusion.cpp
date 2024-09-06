// libro de uva

// Arrays para explorar las 8 direcciones en una rejilla 2D
int dr[] = { 1, 1, 0, -1, -1, -1, 0, 1 }; // Movimientos en las filas (Sur, Sureste, Este, Noreste, Norte, Noroeste, Oeste, Suroeste)
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 }; // Movimientos en las columnas (Sur, Sureste, Este, Noreste, Norte, Noroeste, Oeste, Suroeste)

// Función de floodfill: explora la componente conexa (CC) de la celda (r, c)
int floodfill(int r, int c, char c1, char c2) {
    // Caso base: si está fuera de los límites de la rejilla, no se cuenta
    if (r < 0 || r >= R || c < 0 || c >= C) return 0; 

    // Si la celda actual no tiene el color que estamos buscando (c1), no se cuenta
    if (grid[r][c] != c1) return 0; 

    int ans = 1; // Cuenta la celda actual porque tiene el color c1

    grid[r][c] = c2; // Cambia el color de la celda para evitar ciclos (ya ha sido visitada)

    // Explora los 8 vecinos de la celda actual
    for (int d = 0; d < 8; d++) {
        ans += floodfill(r + dr[d], c + dc[d], c1, c2); // Suma el resultado de la exploración de vecinos
    }

    return ans; // Devuelve el tamaño total de la componente conexa (CC)
}
