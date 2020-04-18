/*
 * Copyright (C) 2013-2019 Phokham Nonava
 *
 * Use of this source code is governed by the MIT license that can be
 * found in the LICENSE file.
 */

#include "move.h"

#include "gtest/gtest.h"

using namespace pulse;

TEST(movetest, testCreation) {
	int move = move::valueOf(movetype::PAWNPROMOTION, Square::a7, Square::b8, piece::WHITE_PAWN, piece::BLACK_QUEEN,
			piecetype::KNIGHT);

	EXPECT_EQ(+movetype::PAWNPROMOTION, move::getType(move));
	EXPECT_EQ(+Square::a7, move::getOriginSquare(move));
	EXPECT_EQ(+Square::b8, move::getTargetSquare(move));
	EXPECT_EQ(+piece::WHITE_PAWN, move::getOriginPiece(move));
	EXPECT_EQ(+piece::BLACK_QUEEN, move::getTargetPiece(move));
	EXPECT_EQ(+piecetype::KNIGHT, move::getPromotion(move));
}

TEST(movetest, testPromotion) {
	int move = move::valueOf(movetype::PAWNPROMOTION, Square::b7, Square::c8, piece::WHITE_PAWN, piece::BLACK_QUEEN,
			piecetype::KNIGHT);

	EXPECT_EQ(+piecetype::KNIGHT, move::getPromotion(move));
}
