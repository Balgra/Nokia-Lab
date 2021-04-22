using ConsoleApp1;
using NUnit.Framework;

namespace TestConsolApp
{
    
    public class BowlingScoreTestSuite
    {
        
        [Test]
        public void GutterGame()
        {   
            Game bowlingGame= new Game();
            //Arrange
            for (int i = 0; i < 20; i++)
            {
                bowlingGame.Roll(0);
            }

            //Act+Assert.
            Assert.AreEqual(0,bowlingGame.CalculateScore());
        }

        [Test]
        public void AllOnesGames()
        {
            Game bowlingGame= new Game();
  
            for (int i = 0; i < 20; i++)
            {
                bowlingGame.Roll(1);
            }

            Assert.AreEqual(20,bowlingGame.CalculateScore());
        }
            
        [Test]
        public void OneSpareGame()
        {
            Game bowlingGame= new Game();
            //Arrange
            bowlingGame.Roll(3);
            bowlingGame.Roll(7);
            bowlingGame.Roll(1);
            for (int i = 0; i < 17; i++)
            {
                bowlingGame.Roll(0);
            }
            Assert.AreEqual(12,bowlingGame.CalculateScore());
        }
        
            
        [Test]
        public void OneStrikeGame()
        {
            Game bowlingGame= new Game();
            //Arrange
            bowlingGame.Roll(3);
            bowlingGame.Roll(7);
            bowlingGame.Roll(1);
            for (int i = 0; i < 17; i++)
            {
                bowlingGame.Roll(0);
            }
            //  RollMany(16, 0);
                
            Assert.AreEqual(12,bowlingGame.CalculateScore());
        }

        [Test]
        public void PerfectGame()
        {
            Game bowlingGame= new Game();
            //Arrange
            for (int i = 0; i < 12; i++)
            {
                bowlingGame.Roll(10);
            }
            //RollMany(12, 0);
                
            Assert.AreEqual(300,bowlingGame.CalculateScore());
        }

    }
    
}