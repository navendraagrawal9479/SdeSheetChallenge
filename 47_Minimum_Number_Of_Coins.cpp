int findMinimumCoins(int amount) 
{
    // Write your code here
    int denominations[9]={1000,500,100,50,20,10,5,2,1};
    int coins=0;
    for(int i=0;i<9;i++){
        coins+=amount/denominations[i];
        amount=amount%denominations[i];
    }
    return coins;
}
