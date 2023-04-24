#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canConstruct(char * ransomNote, char * magazine){
    int ransomLen = strlen(ransomNote);
    int magazineLen = strlen(magazine);
    int letterFreq[26] = {0}; // array to keep frequency of each letter in magazine
    
    // populate the letter frequency array for magazine
    for (int i = 0; i < magazineLen; i++) {
        letterFreq[magazine[i] - 'a']++;
    }
    
    // check if ransomNote can be constructed
    for (int i = 0; i < ransomLen; i++) {
        if (letterFreq[ransomNote[i] - 'a'] > 0) {
            letterFreq[ransomNote[i] - 'a']--;
        } else {
            return false;
        }
    }
    
    return true;
}

int main() {
    char *ransomNote = "aa";
    char *magazine = "aab";
    
    if (canConstruct(ransomNote, magazine)) {
        printf("Ransom note can be constructed.\n");
    } else {
        printf("Ransom note cannot be constructed.\n");
    }
    
    return 0;
}
