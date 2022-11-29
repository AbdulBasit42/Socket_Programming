//program to encrypt and decrypt a message using the playfair cipher

#include <bits/stdc++.h>
using namespace std;

//function to remove spaces from the string

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

//function to remove duplicate characters from the string

string removeDuplicates(string str)
{
    for(int i=0;i<str.length();i++)
    {
        for(int j=i+1;j<str.length();j++)
        {
            if(str[i]==str[j])
            {
                str.erase(j,1);
                j--;
            }
        }
    }
    return str;
}

//function to generate the key matrix

void generateKeyMatrix(string key, char keyMatrix[5][5])
{
    string keyword = removeDuplicates(key);
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    keyword += alphabet;
    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            keyMatrix[i][j] = keyword[k];
            k++;
        }
    }
}

//function to find the location of each character

void findLocation(char keyMatrix[5][5], char c, int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyMatrix[i][j] == c)
            {
                arr[0] = i;
                arr[1] = j;
                break;
            }
        }
    }
}

//function to encrypt the message

string encryptMessage(string message, char keyMatrix[5][5])
{
    string encryptedMessage = "";
    for (int i = 0; i < message.length(); i += 2)
    {
        int loc[2] = {0, 0};
        int loc2[2] = {0, 0};
        findLocation(keyMatrix, message[i], loc);
        findLocation(keyMatrix, message[i + 1], loc2);
        if (loc[0] == loc2[0])
        {
            encryptedMessage += keyMatrix[loc[0]][(loc[1] + 1) % 5];
            encryptedMessage += keyMatrix[loc2[0]][(loc2[1] + 1) % 5];
        }
        else if (loc[1] == loc2[1])
        {
            encryptedMessage += keyMatrix[(loc[0] + 1) % 5][loc[1]];
            encryptedMessage += keyMatrix[(loc2[0] + 1) % 5][loc2[1]];
        }
        else
        {
            encryptedMessage += keyMatrix[loc[0]][loc2[1]];
            encryptedMessage += keyMatrix[loc2[0]][loc[1]];
        }
    }
    return encryptedMessage;
}

//function to decrypt the message

string decryptMessage(string message, char keyMatrix[5][5])
{
    string decryptedMessage = "";
    for (int i = 0; i < message.length(); i += 2)
    {
        int loc[2] = {0, 0};
        int loc2[2] = {0, 0};
        findLocation(keyMatrix, message[i], loc);
        findLocation(keyMatrix, message[i + 1], loc2);
        if (loc[0] == loc2[0])
        {
            decryptedMessage += keyMatrix[loc[0]][(loc[1] + 4) % 5];
            decryptedMessage += keyMatrix[loc2[0]][(loc2[1] + 4) % 5];
        }
        else if (loc[1] == loc2[1])
        {
            decryptedMessage += keyMatrix[(loc[0] + 4) % 5][loc[1]];
            decryptedMessage += keyMatrix[(loc2[0] + 4) % 5][loc2[1]];
        }
        else
        {
            decryptedMessage += keyMatrix[loc[0]][loc2[1]];
            decryptedMessage += keyMatrix[loc2[0]][loc[1]];
        }
    }
    return decryptedMessage;
}

//main function

int main()
{
    string key, message;
    cout << "Enter the key: ";
    cin >> key;
    cout << "Enter the message: ";
    cin >> message;
    char keyMatrix[5][5];
    generateKeyMatrix(key, keyMatrix);
    message = removeSpaces(message);
    if (message.length() % 2 != 0)
    {
        message += 'X';
    }
    string encryptedMessage = encryptMessage(message, keyMatrix);
    cout << "Encrypted message: " << encryptedMessage << endl;
    string decryptedMessage = decryptMessage(encryptedMessage, keyMatrix);
    cout << "Decrypted message: " << decryptedMessage << endl;
    return 0;

}

