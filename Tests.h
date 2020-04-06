#pragma once

struct Tests
{
	static void test0();

	/**
	 *@brief Simple test
	 *
	 */
	static void test1();

	/**
	 *@brief Extension -> Base -> Extension
	 *
	 */
	static void test2();

	/**
	 *@brief Base -> Extension -> Base
	 *
	 */
	static void test3();
};
