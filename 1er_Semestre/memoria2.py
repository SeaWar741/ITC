#Proyecto integrador - Memorama 2.0
#Abraham Cepeda Oseguera
#A00827666
from random import shuffle

#Initialize board with a 6*6 matrix containing numbers from 0 to 35
def create_board():
    board =  [[0] * 6 for  i in range(6)]
    iJ = 0
    for ex in range(6):
        for ey in range(6):
            board[ex][ey] = iJ
            iJ += 1
    return board
    
#desplegar matriz de 6*6 con números del 0 al 35
def display_board(board):
    for ex in range(6):
            for ey in range(6):
                print(f'{board[ex][ey]:<20}', end='')
                #print(str(board[ex][ey]) + ' ' * (20-len(str(board[ex][ey]))), end="")
            print()

#Inicializar juego es la suma de la matriz de paises y capitales, lo cual da una matriz de 6*6 que se revuelve cada vez que se inicializa
def create_game():
    countries_capitals = ['MM - Mexico','UW - USA', 'GB - Germany',
                          'IR - Italy', 'FP - France', 'CO - Canada', 'CP - China',
                          'JT - Japan', 'IN - India', 'GG - Guatemala', 'CS - Chile',
                          'AB - Argentina', 'KT - Kiribati', 'GA - Greece', 'HB - Hungary',
                          'IT - Iran', 'ID - Ireland', 'GA - Ghana', 'MM - Mexico','UW - Washington',
                          'GB - Berlin', 'IR - Roma', 'FP - Paris', 'CO - Ottawa', 'CP - Pekín',
                          'JT - Tokio', 'IN - New Dheli', 'GG - Guatemala', 'CS - Santiago',
                          'AB - Buenos Aires', 'KT - Tarawa', 'GA - Athens', 'HB - Budapest',
                          'IT - Tehran', 'ID - Dublin', 'GA - Accra']
    shuffle(countries_capitals)
    game = [[0] * 6 for _ in range(6)]
    count = -1
    for ex in range(6):
        for ey in range(6):
            count += 1
            game[ex][ey] = countries_capitals[count]
    return game

#Display game, a matrix of 6*6 containg strings (countries and capitals)
def display_game(game):
    for ex in range(6):
        for ey in range(6):
            print(f'{game[ex][ey]:<20}', end='')
            #print(str(game[ex][ey]) + ' ' * (20-len(game[ex][ey])), end="")
        print()
        
#read the numbers and validate them
def get_number(board):
    num = int(input('Enter the first number: '))
    row = num // 6
    col = num % 6
    while num < 0 or num > 35 or board[row][col] != num:
        num = int(input('Enter a valid first number: '))
        row = num // 6
        col = num % 6
    num2 = int(input('Enter the second number: '))
    row2 = num2 // 6
    col2 = num2 % 6
    while num2 == num or num2 < 0 or num2 > 35 or board[row2][col2] != num2:
        num2 = int(input('Enter a valid second number: '))
        row2 = num2 // 6
        col2 = num2 % 6
    return [num, num2, row, col, row2, col2]

#Display the board with the value of each card and check if they are a pair or not
def display_player_board(board, game, num1, num2, row, col, row2, col2, ptsP1, ptsP2, player_counter):
    board[row][col] = '|' + game[row][col]
    board[row2][col2] = '|' + game[row2][col2]
    display_board(board)
    key1 = game[row][col][:2]
    key2 = game[row2][col2][:2]
    if key1 == key2:
        print('You got it right!!!')
        board[row][col] = game[row][col]
        board[row2][col2] = game[row2][col2]
        if player_counter % 2 != 0:
            ptsP1 += 1
        else:
            ptsP2 += 1
    else:
        board[row][col] = num1
        board[row2][col2] = num2
    return board, ptsP1, ptsP2

#Main function
def main():
    ptsP1 = 0
    ptsP2 = 0
    player_counter = 1
    answer = 'si'
    board = create_board()
    game = create_game()
    print('You are about to play a memory game regarding countries and their capitals!')
    while answer.lower() == 'si' and (ptsP1 + ptsP2 < 18):
        display_board(board)
        display_game(game)
        print('Player 1 turn')
        num1, num2, row, col, row2, col2 = get_number(board)
        #display_player_board(board, game, num1, num2, row, col, row2, col2)
        board, ptsP1, ptsP2 = display_player_board(board, game, num1, num2, row, col, row2, col2, ptsP1, ptsP2, player_counter)
        print('Current points player 1: ', ptsP1)
        player_counter += 1
        answer = input('Quieres seguir? (si/no)')
        if answer.lower() == 'si':
            display_board(board)
            display_game(game)
            print('Player 2 turn')
            num1, num2, row, col, row2, col2 = get_number(board)
            #display_player_board(board, game, num1, num2, row, col, row2, col2)
            board, ptsP1, ptsP2 = display_player_board(board, game, num1, num2, row, col, row2, col2, ptsP1, ptsP2, player_counter)
            print('Current points player 2: ', ptsP2)
            player_counter += 1
            answer = input('Quieres seguir? (si/no)')
    if answer.lower() == 'no':
        print('Points Player1:', ptsP1, 'Points Player2:', ptsP2)
    else:
        print('The game  has finished!')
        if ptsP1 > ptsP2:
            print('Player1 is the winner!! with ',)
        elif ptsP1 < ptsP2:
            print('Player2 is the winner!!')
        else:
            print('It is a tie!')
#Initialize main function
main()