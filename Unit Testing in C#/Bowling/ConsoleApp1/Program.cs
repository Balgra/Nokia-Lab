// nu mai mult de 4 linii de cod in fiecare metoda
// sa nu avem if-uri // instructiuni de decizie, nici semnul intrebarii.
// si sa nu avem instructiuni de buclare
// 

namespace ConsoleApp1
{
    public class Game
    {
        public int[] rolls = new int[25];
        private int _current;
        public int CalculateScore()
        {
            int score = 0;
            int i = 0;
            for(int frame = 0; frame < 10; frame++)
            {
                int consecutiveTwoScore = rolls[i] + rolls[i + 1];
                
                if (rolls[i] == 10) //strike
                {
                    score +=consecutiveTwoScore + rolls[i + 2];
                    i += 1;
                }
                else
                {
                    //spare
                    if (consecutiveTwoScore == 10)
                    {
                        score += consecutiveTwoScore + rolls[i + 2];
                    }
                    else
                    {
                        score += consecutiveTwoScore;

                    }

                    i += 2;
                }
            }

            return score;

        }

        public void Roll(int pins)
        {
            rolls[_current++] = pins;

        }
        
        static void Main()
        {
        }
    }
    

}