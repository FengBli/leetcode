// Status: AC, 40ms, beats 100% 

char* thousandInvert(int num) {
    switch(num) {
        case 1:
            return "M";
        case 2:
            return "MM";
        case 3:
            return "MMM";
        default:
            return "";
    }
}

char* hundredInvert(int num) {
    switch(num) {
        case 1:
            return "C";
        case 2:
            return "CC";
        case 3:
            return "CCC";
        case 4:
            return "CD";
        case 5:
            return "D";
        case 6:
            return "DC";
        case 7:
            return "DCC";
        case 8:
            return "DCCC";
        case 9:
            return "CM";
        default:
            return "";
    }
}

char* lowestInvert(int num) {
    switch(num) {
        case 1:
            return "I";
        case 2:
            return "II";
        case 3:
            return "III";
        case 4:
            return "IV";
        case 5:
            return "V";
        case 6:
            return "VI";
        case 7:
            return "VII";
        case 8:
            return "VIII";
        case 9:
            return "IX";
        default:
            return "";
    }
}

char* tenInvert(int num) {
    switch(num) {
        case 1:
            return "X";
        case 2:
            return "XX";
        case 3:
            return "XXX";
        case 4:
            return "XL";
        case 5:
            return "L";
        case 6:
            return "LX";
        case 7:
            return "LXX";
        case 8:
            return "LXXX";
        case 9:
            return "XC";
        default:
            return "";
    }
}


char* intToRoman(int num) {
    int thousand, hundred, ten, lowest;
    char *res;
    int MAX = 30;

    thousand = num / 1000;
    hundred = num%1000 / 100;
    ten = num%100 / 10;
    lowest = num % 10;

    res = (char*) malloc(sizeof(char)*MAX);
    strcat(res, thousandInvert(thousand));
    strcat(res, hundredInvert(hundred));
    strcat(res, tenInvert(ten));
    strcat(res, lowestInvert(lowest));

    return res;


    // printf("%d %d %d %d\n", thousand, hundred, ten, lowest);   
    return "";
}