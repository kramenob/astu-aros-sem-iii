/**
 * @brief  Self work №04
 */

#include "header.04.hpp"

namespace sw04
{

	void taskI();
	void taskII();
	void taskIII();
	void taskIV();
	void taskV();

	void index()
	{

		// print message introduction in program
		message(CURRENT_WORK_TYPE, CURRENT_NUMBER, "intro");

		message( CURRENT_WORK_TYPE, CURRENT_NUMBER, "taskI"   ); taskI();
		message( CURRENT_WORK_TYPE, CURRENT_NUMBER, "taskII"  ); taskII();
		message( CURRENT_WORK_TYPE, CURRENT_NUMBER, "taskIII" ); taskIII();
		message( CURRENT_WORK_TYPE, CURRENT_NUMBER, "taskIV"  ); taskIV();
		message( CURRENT_WORK_TYPE, CURRENT_NUMBER, "taskV"   ); taskV();

		// finish
		return;
	}

}