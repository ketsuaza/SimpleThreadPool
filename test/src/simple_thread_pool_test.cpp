//
// Created by Konstantin Gredeskoul on 5/16/17.
//
#include "gtest/gtest.h"

class SimpleThreadPoolTest : public ::testing::Test 
{

protected:
  virtual void SetUp() 
  {
  };

  virtual void TearDown() 
  {
  };

  virtual void check(int thread_num) 
  {
  }
};

TEST_F(SimpleThreadPoolTest, add) 
{
  // addして実行させて、期待通りの結果が帰ってくるか。
}

TEST_F(SimpleThreadPoolTest, stop) 
{
  // 処理を止められるか。
}

// stopができていること前提
TEST_F(SimpleThreadPoolTest, resume) 
{
  // 処理を再開させれらるか。
}