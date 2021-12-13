#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct login_page {
    char nickname[20];
    char password[20];
};

struct new_user{
    char username[20];
    char password[20];
};
void sign_tree(){
    int d, m;
    
    printf("Enter date (1-31): ");
    scanf("%d", &d);
    
    printf("Enter month (1-12): ");
    scanf("%d", &m);
    
    if((m==12&&d>=22)||(m==1&&d<=19))
        printf("\nYour Zodiac Sign is Capricorn.\n");
    else if((m==1&&d>=20)||(m==2&&d<=17))
        printf("\nYour Zodiac Sign is Aquarius.\n");
    else if((m==2&&d>=18)||(m==3&&d<=19))
        printf("\nYour Zodiac Sign is Pisces.\n");
    else if((m==3&&d>=20)||(m==4&&d<=19))
        printf("\nYour Zodiac Sign is Aries.\n");
    else if((m==4&&d>=20)||(m==5&&d<=20))
        printf("\nYour Zodiac Sign is Taurus.\n");
    else if((m==5&&d>=21)||(m==6&&d<=20))
        printf("\nYour Zodiac Sign is Gemini.\n");
    else if((m==6&&d>=21)||(m==7&&d<=22))
        printf("\nYour Zodiac Sign is Cancer.\n");
    else if((m==7&&d>=23)||(m==8&&d<=22))
        printf("\nYour Zodiac Sign is Leo.\n");
    else if((m==8&&d>=23)||(m==9&&d<=22))
        printf("\nYour Zodiac Sign is Virgo.\n");
    else if((m==9&&d>=23)||(m==10&&d<=22))
        printf("\nYour Zodiac Sign is Libra.\n");
    else if((m==10&&d>=23)||(m==11&&d<=21))
        printf("\nYour Zodiac Sign is Scorpio.\n");
    else if((m==11&&d>=20)||(m==12&&d<=17))
        printf("\nYour Zodiac Sign is Sagittarius.\n");
    else
        printf("\nYou Typed Wrongly.\n");
    
}


void lucky_color() {
    char line[128];
    char colors[75][128];
    int i = 0;
    
    FILE *fColors = fopen("colors.txt", "r");
    
    while (fgets(line, sizeof(line), fColors)){
        strcpy(colors[i], line);
        i++;
    }
    
    fclose(fColors);
    
    printf("\nYour lucky color: %s", colors[rand() % 75]);
}

void lucky_number() {
    char line[128];
    int numbers[100];
    int i = 0;
    
    FILE *fNumbers = fopen("lucky_numbers.txt", "r");
    
    while (fgets(line, sizeof(line), fNumbers)) {
        numbers[i] = atoi(line);
        i++;
    }
    
    fclose(fNumbers);
    
    printf("\nYour lucky number: %i\n", numbers[rand() % 100]);
}

void comments(){
    char line[1000];
    char comments[12][9999];
    
    FILE *fComments = fopen("comments.txt", "r");
    
    int i = 0;
    while (fgets(line, sizeof(line), fComments)) {
        char *sign = strtok(line, "!");
        strcpy(comments[i], strtok(NULL, "!"));
        i++;
    }
    fclose(fComments);
    
    printf("Your comment: %s", comments[rand() % 11]);
}


void main_menu(){
    int selection;
    
    do {
        printf("\n");
        printf("1) Zodiac Sign of Yours\n");
        printf("2) Lucky Color of The Day\n");
        printf("3) Lucky Number of Your Sign\n");
        printf("4) Personality Traits of Your Zodiac Sign\n");
        printf("0) QUIT\n");
        printf("Which feature do you want to choose: ");
        
       // do {
            scanf("%i", &selection);
       // } while( selection == '\n' );
        
        switch (selection) {
            case 1:
                sign_tree();
                break;
            case 2:
                lucky_color();
                break;
            case 3:
                lucky_number();
                break;
            case 4:
                comments();
                break;
            case 0:
            printf("SEE YOU!\n");
            exit(1);
            break;
                
            default:
                printf("Write something between 1 and 4. \n");
                main_menu();
                break;
        }
    } while(selection >= 1 && selection <= 4);
}

int authenticate(struct login_page *user) {
    FILE *ptr = fopen("users.txt", "r");
    char line[1000];
    
    while (fgets(line, sizeof(line), ptr) != NULL)
    {
        char *fUsername = strtok(line, ",");
        char *fPassword = strtok(NULL, ",\n");
        
        if(strcmp(user->nickname, fUsername) == 0 && strcmp(user->password, fPassword) == 0) {
            return 1;
            break;
        }
    }
    
    fclose(ptr);
    
    return 0;
}

void login_page(){
    struct login_page *user = (struct login_page*)malloc(sizeof(struct login_page));
    
    printf("Please enter your nickname: ");
    scanf("%s", user ->nickname);
    
    printf("Please enter your password: ");
    scanf("%s", user ->password);
    
    int result = authenticate(user);
    
    if (result > 0) {
        printf("\nWelcome %s!\n", user->nickname);
        main_menu();
    }
    else {
        printf("\nNo user found. \n");
        login_page();
    }
}


void createUser() {
    struct new_user *new = (struct new_user *)malloc(sizeof(struct new_user));
    
    
    printf("username: ");
    scanf("%s", new->username);
    printf("password: ");
    scanf("%s", new ->password);
    
    FILE *user = fopen("users.txt", "a");
    
    fprintf(user, "%s,%s\n", new->username, new->password);
    
    fclose(user);
    
    printf("Your account has been created. You can use your credentials above. \n");
    
    login_page();
}

void dataFile() {
    
    //colors.txt olusturma
    FILE *colorPtr = fopen("colors.txt", "r");
    
    if (colorPtr == NULL) {
        char arrColor [500] = {"amber\nash\nasphalt\nauburn\navocado\naquamarine\nazure\nbeige\nbisque\nblack\nblue\nbone\nbordeaux\nbrass\nbronze\nbrown\nburgundy\ncamel\ncaramel\ncanary\nceleste\ncerulean\nchampagne\ncharcoal\nchartreuse\nchestnut\nchocolate\ncitron\nclaret\ncoal\ncobalt\ncoffee\ncoral\ncorn\ncream\ncrimson\ncyan\ndenim\ndesert\nebony\necru\nemerald\nfeldspar\nfuchsia\ngold\ngray\ngreen\nheather\nindigo\nivory\njet\nkhaki\nlime\nmagenta\nmaroon\nmint\nnavy\nolive\norange\npink\nplum\npurple\nred\nrust\nsalmon\nsienna\nsilver\nsnow\nsteel\ntan\nteal\ntomato\nviolet\nwhite\nyellow\n"};
        FILE *colorWritePtr = fopen("colors.txt", "w");
        fclose(colorWritePtr);
        
        colorWritePtr = fopen("colors.txt", "a");
        
        fprintf(colorWritePtr,"%s",arrColor);
        
        fclose(colorWritePtr);
    }
    //numbers.txt olusturma
    FILE *numberPtr = fopen("lucky_numbers.txt", "r");
    
    if (numberPtr == NULL) {
        char arrNumber [500] = {"1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n 51\n 52\n 53\n 54\n 55\n 56\n 57\n 58\n 59\n 60\n 61\n 62\n 63\n 64\n 65\n 66\n 67\n 68\n 69\n 70\n 71\n 72\n 73\n 74\n 75\n 76\n 77\n 78\n 79\n 80\n 81\n 82\n 83\n 84\n 85\n 86\n 87\n 88\n 89\n 90\n 91\n 92\n 93\n 94\n 95\n 96\n 97\n 98\n 99\n 100\n"};
        FILE *numberWritePtr = fopen("lucky_numbers.txt", "w");
        fclose(numberWritePtr);
        
        numberWritePtr = fopen("lucky_numbers.txt", "a");
        
        fprintf(numberWritePtr,"%s",arrNumber);
        
        fclose(numberWritePtr);
    }
    //comments.txt olusturma
    FILE *commentPtr = fopen("comments.txt","r");
    
    if (commentPtr == NULL) {
        char arrComment [9999] = {"Virgo!Clever, analytical and methodical, the native of the sixth house of the Western zodiac easily assimilates new knowledge. Pragmatic and meticulous.\nPisces!Deeply intuitive, even mystical, the double and changeable personality of the native of the twelfth sign of the western zodiac gives him a clear-sighted and sentimental nature, but also a tendency to depression. His utopian ideas, just like the little attraction Science has for him, are in perfect agreement with his strong religious and mystical bent.\nLeo!Attractive and charismatic, he naturally inspires admiration from others. His haughty and arrogant tendency should be contained as much as he can, especially if he wishes to keep close ties with his family and their friends alike.\nAquarius!A happy loner, capable of infidelity when he is in a relationship, he is able to display unsympathetic and harsh behavior with foreigners and family alike.While he can get caught in terrible anger outbursts, it's not uncommon that the negligence and lack of sensitivity.\nTaurus!The second zodiac sign of the solar calendar, It is traditionally associated with plowing, when the reading of constellations of Western astrology was still closely related to agriculture, the main activity of humanity for thousands of years.\nGemini!Third zodiac sign of the solar calendar, Gemini is a natural messenger and traveler. Charismatic and gifted for speech, diplomacy is one of his main talents, offset by his incapacity to make decisions.\nCancer!The person born under the fourth zodiac sign of the solar calendar has a curious, versatile and dreamy personality, with a tendency to superstition and melancholy. Shy and even naive, not cartesian for a penny, he even has mystical aspirations, whereas his depressive nature can sometimes lead him to alcohol abuse.\nLibra!Often nice, attractive and intelligent, the person born under the protection of the constellation of this zodiac sign, seventh zodiac sign of Western astrology, is a natural born artist. Gifted with great sensitivity, his artistic ability can only be tempered by an episodic lack of curiosity.\nScorpio!Eighth zodiac sign of Western astrology, the person born while the sun crosses the constellation of Scorpio is intelligent, creative, curious, sensual, but also prone to depression. He is faithful with his friends, but vindictive and underhanded when he feels threatened.\nSagittarius!Ninth zodiac sign of the Western calendar, the person born under the constellation of it is idealistic, peaceful, optimistic and independent. With his family or with his friends, he is an ideal companion, thanks to his friendly and easy-going nature. He actually always tries to be helpful and is never short of good advice.\nCapricorn!Ambitious, patient, meticulous, gifted with a high level of concentration, the native of the zodiac sign of the Capricorn tends to accomplish himself in the second part of his life. Skeptical or even indifferent to religion, the person born during the crossing of the sun with the constellation of he is a thinker, even sometimes a philosopher, who greatly appreciates long walks along the river or in the forest. Similarly to the plants he likes so much and whose growth is slow and deserve care and attention, his rise in life seems slow and difficult.\nAries!The most compatible signs with generally considered to be Gemini, Leo, Sagittarius and Aquarius. The least compatible signs with generally considered to be Cancer and Capricorn. Comparing sun signs can give a good general idea of compatibility.\n"};
        FILE *commentWritePtr = fopen("comments.txt","w");
        fclose (commentWritePtr);
        
        commentWritePtr = fopen("comments.txt","a");
        fprintf(commentWritePtr,"%s",arrComment);
        
        fclose(commentWritePtr);
    }
    //not: her iki menuyede quit fonksiyonu
}

int main(){
    dataFile();
    srand(getpid());
    
    int op;
    
    
    printf("\t\t\t\tWELCOME TO ZODIAC SIGN FINDER\n\n");
    printf("1)LOG IN\n");
    printf("2)NEW USER (Create an account)\n");
    printf("0)QUIT\n");
    printf("Please make your decision: ");
    scanf("%d", &op);
    
    switch (op) {
        case 1:
            login_page();
            break;
        case 2:
            createUser();
            break;
        case 0:
            printf("SEE YOU!\n");
            exit(1);
            break;
    }
    
    return 0;
}
