#include <iostream>
using namespace std;
typedef int score;
typedef int playerLvl;
typedef string ability;

struct pcSheet {
    string playerClass;
    string playerAncestry;
    string pcName;
    string pcPronouns;
    score scoreArr[6];
    playerLvl level;
};

string ancestryArr[3] = {"Human", "Elf", "Dwarf"};
string classArr[13] = {
    "Fighter", "Rogue", "Cleric",
    "Barbarian", "Bard", "Paladin",
    "Wizard", "Sorcerer", "Artificer", "Druid"
};

string playerClass;
string playerAncestry;
string pcName;
string pcPronouns;
string possiblePros[3] = {"He/Him", "She/Her", "They/Them"};
score defAS = 8;
score pointsLeft = 27;

bool moveOn = false;
int yesNo = 0;
bool finishedChange = false;

score scoreArr[6];
ability abilityArr[6] = {"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"};


string getName() {
    string pName;
    cout << "What would you like your character's name to be?\n";
    cin >> pName;
    return pName;
}

string getPros() {
    string pPros;
    int choice = 0;
    bool valid = false;
    cout << "What are your character's pronouns?\n1: He/Him\n2: She/Her\n3: They/Them\n";

    while (!valid) {
        cin >> choice;
        if (choice == 0 || choice > 3) {
            cout << "Invalid response, please enter 1, 2, or 3.\n";
            valid = false;
        } else {
            pPros = possiblePros[choice - 1];

            valid = true;
        }
    }


    return pPros;
}


string getClass() {
    string pClass;
    cout << "What class would you like your character to be?\n";
    cin >> pClass;
    return pClass;
}

string getAncestry() {
    string ancestry;
    cout << "What ancestry does your character have?\n";
    cin >> ancestry;
    return ancestry;
}

void abilityChange() {
    int scoreToChange = 0;
    int amtToAdd = 0;
    bool add = false;
    cout << "Which ability score would you like to change?\n" <<
            "1: Strength\n2: Dexterity\n3: Constitution\n4: Intelligence\n5: Wisdom\n6: Charisma.\n"
            << "Please enter the number next to the score you wish to change.\n";
    cin >> scoreToChange;
    while (1 > scoreToChange or scoreToChange > 6) {
        cout << "\nInvalid response, please enter the number next to the score you wish to change\n";
        cin >> scoreToChange;
    }
    scoreToChange -= 1;


    cout << "Would you like to add or subtract points?\n1: Add\n2: Subtract\n";
    cin >> yesNo;
    bool valid = false;
    while (!valid) {
        switch (yesNo) {
            case 1:
                add = true;
                valid = true;
                break;
            case 0:
                add = false;
                valid = true;
                break;
            default: {
                cout << "Invalid response, please enter 1 for Add or 2 for Subtract.\n";
                cin >> yesNo;
                valid = false;
                break;
            }
        }
    }
    if (add) {
        cout << "How many points would you like to add to " << abilityArr[scoreToChange] << "? \n";
        cout << "You have " << pointsLeft << " points remaining.\n";
        cin >> amtToAdd;
        while (scoreArr[scoreToChange] + amtToAdd > 16) {
            cout << "Ability scores are capped at 16 during character creation.\n";
            system("Pause");
            cout << "How many points would you like to add?";
            amtToAdd = 0;
            cin >> amtToAdd;
        }
        scoreArr[scoreToChange] += amtToAdd;
        pointsLeft -= amtToAdd;
        cout << "Your new " << abilityArr[scoreToChange] << " score is " << scoreArr[scoreToChange] << ". You have " <<
                pointsLeft <<
                " points remaining.\n";

    } else {
        cout << "How many points would you like to subtract from " << abilityArr[scoreToChange] << "? \n";
        cout << "You have " << pointsLeft << " points remaining.\n";
        cin >> amtToAdd;
        scoreArr[scoreToChange] -= amtToAdd;
        pointsLeft += amtToAdd;
        cout << "Your new " << abilityArr[scoreToChange] << " score is " << scoreArr[scoreToChange] << ". You have " <<
                pointsLeft <<
                " points remaining.\n";
    }


}


int main() {
    for (int i = 0; i < sizeof(scoreArr); i++)
        scoreArr[i] = defAS;

    pcPronouns = getPros();
    pcName = getName();
    // cout << "You chose " << playerClass << " \n";
    playerAncestry = getAncestry();
    playerClass = getClass();

    cout << "Okay, you're playing a " << playerAncestry << " " << playerClass << " named " << pcName <<
            " and your character's pronouns are " << pcPronouns << " .\n";
    system("Pause");
    cout << "Let's to choose your ability scores!\n" << "Your stats are\nStrength:\t" << scoreArr[0] <<
            "\nDexterity:\t" << scoreArr[1] << "\nConstitution:\t" << scoreArr[2] <<
            "\nIntelligence:\t" << scoreArr[3] << "\nWisdom:\t\t" << scoreArr[4] << "\nCharisma:\t" << scoreArr[5] <<
            "\n";
    cout << "You may distribute 27 points throughout your stats up to a maximum of 16," << ""
            "\nhowever, raising a stat above 13 requires 2 points each.\n";
    system("Pause");
    while (!finishedChange) {
        abilityChange();
        cout << "Would you like to keep changing your scores?\n1: Yes\n2: No\n";
        cin >> yesNo;
        if (yesNo == 2) {
            finishedChange = true;
            yesNo = 0;
        }
    }
}
