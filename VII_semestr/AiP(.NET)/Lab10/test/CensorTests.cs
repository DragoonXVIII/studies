using api;

namespace test;

public class CensorTests
{
    [Fact]
    public void CensorWord_WordOnBlackList_CensoredProperly()
    {
        var c = new Censor();
        c.Blacklist = new List<string> { "bomba" };
        var result = c.CensorWord("bomba");

        Assert.Equal("b****", result);
    }

    [Fact]
    public void CensorWord_WordOnBlackListDifferentCase_CensoredProperly()
    {
        var c = new Censor();
        c.Blacklist = new List<string> { "bomba" };
        var result = c.CensorWord("BOMBA");

        Assert.Equal("B****", result);
    }

    [Fact]
    public void CensorWord_WordOnBlackListStrangeCase_CensoredProperly()
    {
        var c = new Censor();
        c.Blacklist = new List<string> { "bomba" };
        var result = c.CensorWord("BoMbA");

        Assert.Equal("B****", result);
    }

    [Theory]
    [InlineData("bomba")]
    [InlineData("lis")]
    [InlineData("Bomba")]
    public void CensorWord_WordOnBlackList_FirstLetterStays(string word)
    {
        var c = new Censor();
        c.Blacklist = new List<string> { "bomba", "lis" };
        var result = c.CensorWord(word);

        Assert.Equal(word.Substring(0, 1), result.Substring(0, 1));
    }

    [Theory]
    [InlineData("bomba", 4)]
    [InlineData("Bomba", 4)]
    [InlineData("lis", 2)]
    public void CensorWord_WordOnBlackList_StarsCountMatch(string word, int expected)
    {
        var c = new Censor();
        c.Blacklist = new List<string> { "bomba", "lis" };
        var result = c.CensorWord(word);

        Assert.True(result.Substring(1).All(x => x == '*'));
        Assert.Equal(expected, result.Substring(1).Length);
    }

    [Fact]
    public void CensorWord_WordNotOnBlackList_NotCensored()
    {
        var c = new Censor();
        c.Blacklist = new List<string> { "bomba" };
        var result = c.CensorWord("atomowa");

        Assert.Equal("atomowa", result);
    }

    [Fact]
    public void CensorWord_WordPartiallyOnBlackList_NotCensored()
    {
        var c = new Censor();
        c.Blacklist = new List<string> { "nig" };
        var result = c.CensorWord("knight");

        Assert.Equal("knight", result);
    }

    [Fact]
    public void CensorText_WordNotOnBlackList_NotCensored()
    {
        var c = new Censor();
        c.Blacklist = new List<string> { "bomba" };
        var result = c.CensorWord("atomowa atomowa atomowa");

        Assert.Equal("atomowa atomowa atomowa", result);
    }

    [Fact]
    public void CensorText_WordOnBlackList_Censored()
    {
        var c = new Censor();
        c.Blacklist = new List<string> { "bomba" };
        var result = c.CensorText("bomba bomba bomba");

        Assert.Equal("b**** b**** b****", result);
    }

    [Fact]
    public void CensorText_WordOnBlackList_AllCensored()
    {
        var c = new Censor();
        c.Blacklist = new List<string> { "bomba", "broń", "nienawiść" };
        var result = c.CensorText("bomba atomowa broń jądrowa nienawiść");

        Assert.Equal("b**** atomowa b*** jądrowa n********", result);
    }

    [Fact]
    public void CensorText_WordOnBlackListSingleWord_AllCensored()
    {
        var c = new Censor();
        c.Blacklist = new List<string> { "bomba", "broń", "nienawiść" };
        var result = c.CensorText("bomba");

        Assert.Equal("b****", result);
    }

    [Fact]
    public void CensorText_WordPartiallyOnBlackList_NotCensored()
    {
        var c = new Censor();
        c.Blacklist = new List<string> { "bomb" };
        var result = c.CensorText("bomba bomba bomba");

        Assert.Equal("bomba bomba bomba", result);
    }
}
