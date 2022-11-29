import socket as so
s=so.socket()

print("socket made")


port=1234

s.bind(('localhost', port))

s.listen(3)

print('waiting for connection')

while True:
    c,addr= s.accept()
    datarecv=c.recv(1024).decode()

    # print(datarecv)
    # x=datarecv.split("~")
    # cipher=x[0]
    # keyNew=int(x[1])
    print(datarecv)
    keyNew = input('Enter key to decrypt : ')
    keyNew = int(keyNew)
    # This function receives cipher-text
    # and key and returns the original
    # text after decryption
    def decryptRailFence(cipher, keyNew):

        # create the matrix to cipher
        # plain text key = rows ,
        # length(text) = columns
        # filling the rail matrix to
        # distinguish filled spaces
        # from blank ones
        rail = [['\n' for i in range(len(cipher))]
                    for j in range(keyNew)]
        
        # to find the direction
        dir_down = None
        row, col = 0, 0
        
        # mark the places with '*'
        for i in range(len(cipher)):
            if row == 0:
                dir_down = True
            if row == keyNew - 1:
                dir_down = False
            
            # place the marker
            rail[row][col] = '*'
            col += 1
            
            # find the next row
            # using direction flag
            if dir_down:
                row += 1
            else:
                row -= 1
                
        # now we can construct the
        # fill the rail matrix
        index = 0
        for i in range(keyNew):
            for j in range(len(cipher)):
                if ((rail[i][j] == '*') and
                (index < len(cipher))):
                    rail[i][j] = cipher[index]
                    index += 1
            
        # now read the matrix in
        # zig-zag manner to construct
        # the resultant text
        result = []
        row, col = 0, 0
        for i in range(len(cipher)):
            
            # check the direction of flow
            if row == 0:
                dir_down = True
            if row == keyNew-1:
                dir_down = False
                
            # place the marker
            if (rail[row][col] != '*'):
                result.append(rail[row][col])
                col += 1
                
            # find the next row using
            # direction flag
            if dir_down:
                row += 1
            else:
                row -= 1
        return("".join(result))

    print("\nDecrypted Text: \n")
    print(decryptRailFence(datarecv, keyNew))