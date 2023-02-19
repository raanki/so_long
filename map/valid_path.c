// #include "../so_long.h"

// #include <stdlib.h>
// #include <stdio.h>

// #define ROWS 5
// #define COLS 13

// typedef struct {
//   int row;
//   int col;
// } Cell;

// Cell queue[ROWS * COLS];
// int front = 0, rear = 0;

// // Ajouter une cellule à la queue
// void enqueue(int row, int col) {
//   queue[rear].row = row;
//   queue[rear].col = col;
//   rear++;
// }

// // Retirer une cellule de la queue
// Cell dequeue() {
//   Cell cell = queue[front];
//   front++;
//   return cell;
// }

// // Vérifier si la queue est vide
// int is_empty() {
//   return front == rear;
// }

// int bfs(int row, int col, int dest_row, int dest_col, char **grid, int num_items) {
//   // Matrice pour stocker les cellules visitées et les distances
//   int visited[ROWS][COLS];
//   int distances[ROWS][COLS];

//   // Queues pour stocker les coordonnées des cellules à explorer
//   int rowQueue[ROWS*COLS], colQueue[ROWS*COLS];
//   int front = 0, rear = 0;

//   // Tableaux pour stocker les mouvements possibles
//   int rowMoves[] = {-1, 0, 1, 0};
//   int colMoves[] = {0, 1, 0, -1};

//   int rowCurrent, colCurrent, rowNext, colNext, i;

//   // Initialisation de la matrice visitée et des distances
//   for (i = 0; i < ROWS; i++) {
//     for (int j = 0; j < COLS; j++) {
//       visited[i][j] = 0;
//       distances[i][j] = -1;
//       if (grid[i][j] == 'C') {
//         num_items++;
//       }
//     }
//   }

//   // La case de départ est marquée comme visitée et ajoutée à la queue avec une distance de 0
//   visited[row][col] = 1;
//   distances[row][col] = 0;
//   rowQueue[rear] = row;
//   colQueue[rear] = col;
//   rear++;

//   // Tant que la queue n'est pas vide, continuer à explorer les cellules
//   while (front < rear) {
//     // Retirer la cellule actuelle de la queue
//     rowCurrent = rowQueue[front];
//     colCurrent = colQueue[front];
//     front++;

//     // Explorer les cellules adjacentes
//     for (i = 0; i < 4; i++) {
//       rowNext = rowCurrent + rowMoves[i];
//       colNext = colCurrent + colMoves[i];

//       // Vérifier si la cellule est en dehors de la grille
//       if (rowNext < 0 || rowNext >= ROWS || colNext < 0 || colNext >= COLS) {
//         continue;
//       }

//       // Vérifier si la cellule est un obstacle ou a déjà été visitée
//       if (grid[rowNext][colNext] == '1' || visited[rowNext][colNext] == 1) {
//         continue;
//       }

//       // Si la cellule suivante contient un item collectible, décrémenter le nombre d'items restants
//       if (grid[rowNext][colNext] == 'C') {
//         num_items--;
//       }

//       // Marquer la cellule suivante comme visitée et l'ajouter à la queue avec une distance égale à la distance de la cellule courante + 1
//       visited[rowNext][colNext] = 1;
//       distances[rowNext][colNext] = distances[rowCurrent][colCurrent] + 1;
//       rowQueue[rear] = rowNext;
//       colQueue[rear] = colNext;
//       rear++;

//       // Vérifier si la cellule suivante est la destination
//       if (rowNext == dest_row && colNext == dest_col) 
//       { 
//         return distances[rowNext][colNext] + 2;
// }

// // Mettre à jour la distance de la cellule suivante
// distances[rowNext][colNext] = distances[rowCurrent][colCurrent] + 1;

// // Ajouter la cellule suivante à la queue
// queue[rear].row = rowNext;
// queue[rear].col = colNext;
// rear++;
// }
// }

// // Si la destination n'a pas été atteinte, retourner -1
// return -1;
// }

// #include "../so_long.h"

// #include <stdlib.h>
// #include <stdio.h>

// #define ROWS 5
// #define COLS 13

// typedef struct {
//   int row;
//   int col;
// } Cell;

// Cell queue[ROWS * COLS];
// int front = 0, rear = 0;

// // Ajouter une cellule à la queue
// void enqueue(int row, int col) {
//   queue[rear].row = row;
//   queue[rear].col = col;
//   rear++;
// }

// // Retirer une cellule de la queue
// Cell dequeue() {
//   Cell cell = queue[front];
//   front++;
//   return cell;
// }

// // Vérifier si la queue est vide
// int is_empty() {
//   return front == rear;
// }

// int bfs(int row, int col, int dest_row, int dest_col, char **grid, int num_items) {
//   // Matrice pour stocker les cellules visitées et les distances
//   int visited[ROWS][COLS];
//   int distances[ROWS][COLS];

//   // Queues pour stocker les coordonnées des cellules à explorer
//   int rowQueue[ROWS*COLS], colQueue[ROWS*COLS];
//   int front = 0, rear = 0;

//   // Tableaux pour stocker les mouvements possibles
//   int rowMoves[] = {-1, 0, 1, 0};
//   int colMoves[] = {0, 1, 0, -1};

//   int rowCurrent, colCurrent, rowNext, colNext, i;

//   // Initialisation de la matrice visitée et des distances
//   for (i = 0; i < ROWS; i++) {
//     for (int j = 0; j < COLS; j++) {
//       visited[i][j] = 0;
//       distances[i][j] = -1;
//       if (grid[i][j] == 'C') {
//         num_items++;
//       }
//     }
//   }

//   // La case de départ est marquée comme visitée et ajoutée à la queue avec une distance de 0
//   visited[row][col] = 1;
//   distances[row][col] = 0;
//   rowQueue[rear] = row;
//   colQueue[rear] = col;
//   rear++;

//   // Tant que la queue n'est pas vide, continuer à explorer les cellules
//   while (front < rear) {
//     // Retirer la cellule actuelle de la queue
//     rowCurrent = rowQueue[front];
//     colCurrent = colQueue[front];
//     front++;

//     // Explorer les cellules adjacentes
//     for (i = 0; i < 4; i++) {
//       rowNext = rowCurrent + rowMoves[i];
//       colNext = colCurrent + colMoves[i];

//       // Vérifier si la cellule est en dehors de la grille
//       if (rowNext < 0 || rowNext >= ROWS || colNext < 0 || colNext >= COLS) {
//         continue;
//       }

//       // Vérifier si la cellule est un obstacle ou a déjà été visitée
//       if (grid[rowNext][colNext] == '1' || visited[rowNext][colNext] == 1) {
//         continue;
//       }

//       // Si la cellule suivante contient un item collectible, décrémenter le nombre d'items restants
//       if (grid[rowNext][colNext] == 'C') {
//         num_items--;
//       }

//       // Marquer la cellule suivante comme visitée et l'ajouter à la queue avec une distance égale à la distance de la cellule courante + 1
//       visited[rowNext][colNext] = 1;
//       distances[rowNext][colNext] = distances[rowCurrent][colCurrent] + 1;
//       rowQueue[rear] = rowNext;
//       colQueue[rear] = colNext;
//       rear++;

//       // Vérifier si la cellule suivante est la destination
//       if (rowNext == dest_row && colNext == dest_col) {
//         // Si la destination a été atteinte et qu'il n'y a plus d'items restants, retourner la distance
//         if (num_items == 0) {
//           return distances[rowNext][colNext] + 2; // ajouter 2 pour tenir compte de la case de départ et de la case d'arrivée
//         }
//       }
//     }
//   }

//   // Si la destination n'a pas été atteinte, retourner -1
//   return -1;
// }
