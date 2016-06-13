/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
int linearSearch (int tile, int pos);
bool won(void);

int main(int argc, string argv[]) {
    // ensure proper usage
    if (argc != 2) {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX) {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL) {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true) {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1) {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won()) {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0) {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile)) {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void) {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void) {
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void) {
    // TODO
    int max_tile = d*d-1;
    for (int i=0; i < d; i++) {
        for (int j=0; j < d; j++) {
            board[i][j] = max_tile;
            max_tile--;
        }
    }
    
    if (d%2 == 0) {
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1;
    }
    
    board[d][d] = 0;
}

/**
 * Prints the board in its current state.
 */
void draw(void) {
    // TODO
    printf("\n\n\n");
    for (int i = 0; i < d; i++) {
        printf(" ");
        for (int j = 0; j < d; j++) {
            if (board[i][j] != 0) {
                if (board[i][j] > 9) {
                    printf("%i ", board[i][j]);
                }
                else {
                    printf(" %i ", board[i][j]);
                }
            }
            else {
                printf(" ? ");
            }
        }
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile) {
    if (tile >= d*d || tile <= 0) {
        return false;
    } else {
        // 0 means i position, 1 means j position
        int tile_pos_i = linearSearch(tile, 0);
        int tile_pos_j = linearSearch(tile, 1);
        int blank_pos_i = linearSearch(0, 0);
        int blank_pos_j = linearSearch(0, 1);
        
        //test
        //printf("%i", tile_pos_i);
        //printf("%i", tile_pos_j);
        //printf("%i", blank_pos_i);
        //printf("%i", blank_pos_j);
        
        if ((tile_pos_i == blank_pos_i + 1 || tile_pos_i == blank_pos_i - 1) && tile_pos_j == blank_pos_j) {
            board[blank_pos_i][blank_pos_j] = tile;
            board[tile_pos_i][tile_pos_j] = 0;
            return true;
        } else if ((tile_pos_j == blank_pos_j + 1 || tile_pos_j == blank_pos_j - 1) && tile_pos_i == blank_pos_i) {
            board[blank_pos_i][blank_pos_j] = tile;
            board[tile_pos_i][tile_pos_j] = 0;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void) {
    int true_cond = 0;
    int e = d-1;
    
    if (board[d-1][d-1] == 0) {
        true_cond++;
    }
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (board[i][j] == d-e) {
                true_cond++;
                e--;
            }
        }
    }
    if (true_cond == d*d) {
        return true;
    }
    return false;
}

int linearSearch(int tile, int pos) {
    for (int i=0; i < d; i++) {
        for (int j=0; j < d; j++) {
            if (board[i][j] == tile && pos == 0) {
                return i;
            } else if (board[i][j] == tile && pos == 1) {
                return j;
            }
        }
    }
    return 1;
}