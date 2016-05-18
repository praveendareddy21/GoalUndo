/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"

class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}



/************************getOperations() TestCases************************/

TEST(GoalUndoTest, getLatestOperationsWithSingleGoal)
{ GoalUndo g;
  g.addOperation("Goal1","operation1");
  g.addOperation("operation2");
	ASSERT_EQ(g.getOperations(), "operation1 operation2");
}
TEST(GoalUndoTest, getLatestOperationsWithMultipleGoals)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("Goal1","operation1");
  g.addOperation("operation2");
	ASSERT_EQ(g.getOperations(), "operation1 operation2");
}
/************************************************************************************************/

/************************getGoal() TestCases************************/
TEST(GoalUndoTest, getGoalWithNoGoalsAdded)
{ GoalUndo g;
	ASSERT_EQ(g.getGoal(), "");
}
TEST(GoalUndoTest, getLatestGoalWithSingleGoal)
{ GoalUndo g;
  g.addOperation("Goal1","operation1");
  g.addOperation("operation2");
	ASSERT_EQ(g.getGoal(), "Goal1");
}
TEST(GoalUndoTest, getLatestGoalWithMultipleGoals)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("Goal1","operation1");
  g.addOperation("operation2");
	ASSERT_EQ(g.getGoal(), "Goal1");
}
/************************************************************************************************/

/************************addOperation(std::string, std::string) TestCases************************/


TEST(GoalUndoTest, GoalCheckOnaddOperationWithEmptyGoal)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("","operation1");
	ASSERT_EQ(g.getGoal(), "Goal0");
}
TEST(GoalUndoTest, GoalCheckOnaddOperationWithEmptyOperation)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("Goal1","");
	ASSERT_EQ(g.getGoal(), "Goal0");
}
TEST(GoalUndoTest, GoalCheckOnaddOperationWithEmptyOperationAndGoal)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("","");
	ASSERT_EQ(g.getGoal(), "Goal0");
}
TEST(GoalUndoTest, OperationCheckOnaddOperationWithEmptyGoal)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("","operation1");
	ASSERT_EQ(g.getOperations(), "operation0");
}
TEST(GoalUndoTest, OperationCheckOnaddOperationWithEmptyOperation)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("Goal1","");
	ASSERT_EQ(g.getOperations(), "operation0");
}
TEST(GoalUndoTest, OperationCheckOnaddOperationWithEmptyOperationAndGoal)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("","");
	ASSERT_EQ(g.getOperations(), "operation0");
}
TEST(GoalUndoTest, GoalCheckaddOperationWithGoalSpecified)
{ GoalUndo g;
  g.addOperation("Goal1","operation1");
  g.addOperation("operation2");
  g.getGoal();
	ASSERT_EQ(g.getGoal(), "Goal1");
}
/**********************************************************************/



/************************addOperation(std::string ) TestCases************************/



TEST(GoalUndoTest, GoalCheckOnaddOperationBasicWithEmptyOperation)
{ GoalUndo g;
  g.addOperation("operation0");
  g.addOperation("");
	ASSERT_EQ(g.getGoal(), "operation0");
}
TEST(GoalUndoTest, OperationCheckOnaddOperationBasicWithEmptyOperation)
{ GoalUndo g;
  g.addOperation("operation0");
  g.addOperation("");
	ASSERT_EQ(g.getOperations(), "operation0");
}
TEST(GoalUndoTest, GoalCheckOnaddOperationBasicWithEmptyGoallist)
{ GoalUndo g;
  g.addOperation("operation0");
	ASSERT_EQ(g.getGoal(), "operation0");
}
TEST(GoalUndoTest, OperationCheckOnaddOperationBasicWithEmptyGoallist)
{ GoalUndo g;
  g.addOperation("operation0");
	ASSERT_EQ(g.getOperations(), "operation0");
}

/**********************************************************************/





/************************ undoGoal() TestCases************************/

TEST(GoalUndoTest, GoalCheckOnUndoGoalWithSingleGoal)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.undoGoal();
	ASSERT_EQ(g.getGoal(), "");
}
TEST(GoalUndoTest, GoalCheckOnUndoGoalWithMultipleGoal)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("Goal1","operation1");
  g.addOperation("Goal2","operation2");
  g.undoGoal();
	ASSERT_EQ(g.getGoal(), "Goal1");
}
TEST(GoalUndoTest, OperationCheckOnUndoGoalWithMultipleGoal)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("Goal1","operation 0");
  g.addOperation("operation 1");
  g.addOperation("Goal2","operation2");
  g.undoGoal();
	ASSERT_EQ(g.getOperations(), "operation 0 operation 1");
}
TEST(GoalUndoTest, GoalCheckOnUndoGoalWithEmptyGoallist)
{ GoalUndo g;
  g.undoGoal();
	ASSERT_EQ(g.getGoal(), "");
}


/**********************************************************************/

/************************ undoOperation() TestCases************************/

TEST(GoalUndoTest, GoalCheckOnUndoOperationWithSingleGoal)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.undoOperation();
	ASSERT_EQ(g.getGoal(), "");
}
TEST(GoalUndoTest, OperationCheckOnUndoOperationWithSingleGoal)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.undoOperation();
	ASSERT_EQ(g.getOperations(), "");
}
TEST(GoalUndoTest, OperationCheckOnUndoOperationWithSingleLatestOperation)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("Goal1","operation1");
  g.undoOperation();
	ASSERT_EQ(g.getOperations(), "operation0");
}
TEST(GoalUndoTest, GoalCheckOnUndoOperationWithSingleLatestOperation)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("Goal1","operation1");
  g.undoOperation();
	ASSERT_EQ(g.getGoal(), "Goal0");
}
TEST(GoalUndoTest, GoalCheckOnUndoOperationWithMultipleLatestOperation)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("operation1");
  g.addOperation("operation2");
  g.undoOperation();
	ASSERT_EQ(g.getGoal(), "Goal0");
}
TEST(GoalUndoTest, GoalCheckOnUndoOperationWithEmptyGoallist)
{ GoalUndo g;
  g.undoOperation();
	ASSERT_EQ(g.getGoal(), "");
}
TEST(GoalUndoTest, OperationsCheckOnUndoOperationWithEmptyGoallist)
{ GoalUndo g;
  g.undoOperation();
	ASSERT_EQ(g.getOperations(), "");
}

/**********************************************************************/

/************************undoOperation(std::string) TestCases************************/


TEST(GoalUndoTest, OperationCheckOnUndoOperationArgWithMultipleOp)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("operation1");
  g.addOperation("operation3");
  g.addOperation("operation1");
  g.addOperation("operation1");
  g.addOperation("operation2");
  g.undoOperation("operation1");
	ASSERT_EQ(g.getOperations(), "operation0 operation1 operation3 operation1 operation2");
}
TEST(GoalUndoTest, GoalCheckOnUndoOperationArgWithMultipleOp)
{ GoalUndo g;
  g.addOperation("Goal0","operation0");
  g.addOperation("operation1");
  g.addOperation("operation3");
  g.addOperation("operation1");
  g.addOperation("operation1");
  g.addOperation("operation2");
  g.undoOperation("operation1");
	ASSERT_EQ(g.getGoal(), "Goal0");
}
TEST(GoalUndoTest, GoalCheckOnUndoOperationArgWithEmptyGoallist)
{ GoalUndo g;
  g.undoOperation("Rubbish Operation");
	ASSERT_EQ(g.getGoal(), "");
}
TEST(GoalUndoTest, OperationsCheckOnUndoOperationArgWithEmptyGoallist)
{ GoalUndo g;
  g.undoOperation("Rubbish Operation");
	ASSERT_EQ(g.getOperations(), "");
}
TEST(GoalUndoTest, GoalCheckOnUndoUndoOperationArgWithCorrectSingleOperation)
{ GoalUndo g;
  g.addOperation("Goal0", "operation0");
  g.undoOperation("operation0");
	ASSERT_EQ(g.getGoal(), "");
}
TEST(GoalUndoTest, OperationsCheckOnUndoOperationArgWithCorrectSingleOperation)
{ GoalUndo g;
  g.addOperation("Goal0", "operation0");
  g.undoOperation("operation0");
	ASSERT_EQ(g.getOperations(), "");
}
TEST(GoalUndoTest, GoalCheckOnUndoUndoOperationArgWithInCorrectSingleOperation)
{ GoalUndo g;
  g.addOperation("Goal0", "operation0");
  g.undoOperation("operation1");
	ASSERT_EQ(g.getGoal(), "Goal0");
}
TEST(GoalUndoTest, OperationsCheckOnUndoOperationArgWithInCorrectSingleOperation)
{ GoalUndo g;
  g.addOperation("Goal0", "operation0");
  g.undoOperation("operation1");
	ASSERT_EQ(g.getOperations(), "operation0");
}

/**********************************************************************/
