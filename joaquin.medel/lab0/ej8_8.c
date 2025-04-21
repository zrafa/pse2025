int main()
{

    unsigned char RES;
    unsigned char var;
    var = 190;
    RES = (unsigned char)(var * 500) / 190;
    printf("%i", RES);
    //Al pasarlo a unsigned char el truncamiento hace que se pierda infromacion 
}