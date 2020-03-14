#include "PolyLib.h"
#include <assert.h>

PrimitivePoly PrimitivePolyFactory::createPolyOfDegree(int n)
{
	assert(n >= 2);
	assert(n <= 256);

	PrimitivePoly result;
	result.rep.SetLength(n+1);
	NTL::SetCoeff(result.rep, 0, 1);
	switch (n)
	{
		case 2:
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 3:
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 4:
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 5:
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 6:
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 7:
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 8:
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 9:
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			break;
		case 10:
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 11:
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 12:
			NTL::SetCoeff(result.rep, 12, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 13:
			NTL::SetCoeff(result.rep, 13, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 14:
			NTL::SetCoeff(result.rep, 14, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 15:
			NTL::SetCoeff(result.rep, 15, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 16:
			NTL::SetCoeff(result.rep, 16, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 17:
			NTL::SetCoeff(result.rep, 17, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 18:
			NTL::SetCoeff(result.rep, 18, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			break;
		case 19:
			NTL::SetCoeff(result.rep, 19, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 20:
			NTL::SetCoeff(result.rep, 20, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 21:
			NTL::SetCoeff(result.rep, 21, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 22:
			NTL::SetCoeff(result.rep, 22, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 23:
			NTL::SetCoeff(result.rep, 23, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			break;
		case 24:
			NTL::SetCoeff(result.rep, 24, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 25:
			NTL::SetCoeff(result.rep, 25, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 26:
			NTL::SetCoeff(result.rep, 26, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 27:
			NTL::SetCoeff(result.rep, 27, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 28:
			NTL::SetCoeff(result.rep, 28, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 29:
			NTL::SetCoeff(result.rep, 29, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 30:
			NTL::SetCoeff(result.rep, 30, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 31:
			NTL::SetCoeff(result.rep, 31, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 32:
			NTL::SetCoeff(result.rep, 32, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 33:
			NTL::SetCoeff(result.rep, 33, 1);
			NTL::SetCoeff(result.rep, 13, 1);
			break;
		case 34:
			NTL::SetCoeff(result.rep, 34, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 35:
			NTL::SetCoeff(result.rep, 35, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 36:
			NTL::SetCoeff(result.rep, 36, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			break;
		case 37:
			NTL::SetCoeff(result.rep, 37, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 38:
			NTL::SetCoeff(result.rep, 38, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 39:
			NTL::SetCoeff(result.rep, 39, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			break;
		case 40:
			NTL::SetCoeff(result.rep, 40, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 41:
			NTL::SetCoeff(result.rep, 41, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 42:
			NTL::SetCoeff(result.rep, 42, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 43:
			NTL::SetCoeff(result.rep, 43, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 44:
			NTL::SetCoeff(result.rep, 44, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 45:
			NTL::SetCoeff(result.rep, 45, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 46:
			NTL::SetCoeff(result.rep, 46, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			break;
		case 47:
			NTL::SetCoeff(result.rep, 47, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			break;
		case 48:
			NTL::SetCoeff(result.rep, 48, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			break;
		case 49:
			NTL::SetCoeff(result.rep, 49, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			break;
		case 50:
			NTL::SetCoeff(result.rep, 50, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 51:
			NTL::SetCoeff(result.rep, 51, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 52:
			NTL::SetCoeff(result.rep, 52, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 53:
			NTL::SetCoeff(result.rep, 53, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 54:
			NTL::SetCoeff(result.rep, 54, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 55:
			NTL::SetCoeff(result.rep, 55, 1);
			NTL::SetCoeff(result.rep, 24, 1);
			break;
		case 56:
			NTL::SetCoeff(result.rep, 56, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 57:
			NTL::SetCoeff(result.rep, 57, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			break;
		case 58:
			NTL::SetCoeff(result.rep, 58, 1);
			NTL::SetCoeff(result.rep, 19, 1);
			break;
		case 59:
			NTL::SetCoeff(result.rep, 59, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 60:
			NTL::SetCoeff(result.rep, 60, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 61:
			NTL::SetCoeff(result.rep, 61, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 62:
			NTL::SetCoeff(result.rep, 62, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 63:
			NTL::SetCoeff(result.rep, 63, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 64:
			NTL::SetCoeff(result.rep, 64, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 65:
			NTL::SetCoeff(result.rep, 65, 1);
			NTL::SetCoeff(result.rep, 18, 1);
			break;
		case 66:
			NTL::SetCoeff(result.rep, 66, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			break;
		case 67:
			NTL::SetCoeff(result.rep, 67, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 68:
			NTL::SetCoeff(result.rep, 68, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			break;
		case 69:
			NTL::SetCoeff(result.rep, 69, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 70:
			NTL::SetCoeff(result.rep, 70, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 71:
			NTL::SetCoeff(result.rep, 71, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			break;
		case 72:
			NTL::SetCoeff(result.rep, 72, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 73:
			NTL::SetCoeff(result.rep, 73, 1);
			NTL::SetCoeff(result.rep, 25, 1);
			break;
		case 74:
			NTL::SetCoeff(result.rep, 74, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 75:
			NTL::SetCoeff(result.rep, 75, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 76:
			NTL::SetCoeff(result.rep, 76, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 77:
			NTL::SetCoeff(result.rep, 77, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 78:
			NTL::SetCoeff(result.rep, 78, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 79:
			NTL::SetCoeff(result.rep, 79, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			break;
		case 80:
			NTL::SetCoeff(result.rep, 80, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 81:
			NTL::SetCoeff(result.rep, 81, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			break;
		case 82:
			NTL::SetCoeff(result.rep, 82, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			break;
		case 83:
			NTL::SetCoeff(result.rep, 83, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 84:
			NTL::SetCoeff(result.rep, 84, 1);
			NTL::SetCoeff(result.rep, 13, 1);
			break;
		case 85:
			NTL::SetCoeff(result.rep, 85, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 86:
			NTL::SetCoeff(result.rep, 86, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 87:
			NTL::SetCoeff(result.rep, 87, 1);
			NTL::SetCoeff(result.rep, 13, 1);
			break;
		case 88:
			NTL::SetCoeff(result.rep, 88, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			break;
		case 89:
			NTL::SetCoeff(result.rep, 89, 1);
			NTL::SetCoeff(result.rep, 38, 1);
			break;
		case 90:
			NTL::SetCoeff(result.rep, 90, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 91:
			NTL::SetCoeff(result.rep, 91, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 92:
			NTL::SetCoeff(result.rep, 92, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 93:
			NTL::SetCoeff(result.rep, 93, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 94:
			NTL::SetCoeff(result.rep, 94, 1);
			NTL::SetCoeff(result.rep, 21, 1);
			break;
		case 95:
			NTL::SetCoeff(result.rep, 95, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			break;
		case 96:
			NTL::SetCoeff(result.rep, 96, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			break;
		case 97:
			NTL::SetCoeff(result.rep, 97, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			break;
		case 98:
			NTL::SetCoeff(result.rep, 98, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			break;
		case 99:
			NTL::SetCoeff(result.rep, 99, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			break;
		case 100:
			NTL::SetCoeff(result.rep, 100, 1);
			NTL::SetCoeff(result.rep, 37, 1);
			break;
		case 101:
			NTL::SetCoeff(result.rep, 101, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 102:
			NTL::SetCoeff(result.rep, 102, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 103:
			NTL::SetCoeff(result.rep, 103, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			break;
		case 104:
			NTL::SetCoeff(result.rep, 104, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 105:
			NTL::SetCoeff(result.rep, 105, 1);
			NTL::SetCoeff(result.rep, 16, 1);
			break;
		case 106:
			NTL::SetCoeff(result.rep, 106, 1);
			NTL::SetCoeff(result.rep, 15, 1);
			break;
		case 107:
			NTL::SetCoeff(result.rep, 107, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			break;
		case 108:
			NTL::SetCoeff(result.rep, 108, 1);
			NTL::SetCoeff(result.rep, 31, 1);
			break;
		case 109:
			NTL::SetCoeff(result.rep, 109, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 110:
			NTL::SetCoeff(result.rep, 110, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 111:
			NTL::SetCoeff(result.rep, 111, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			break;
		case 112:
			NTL::SetCoeff(result.rep, 112, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			break;
		case 113:
			NTL::SetCoeff(result.rep, 113, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			break;
		case 114:
			NTL::SetCoeff(result.rep, 114, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 115:
			NTL::SetCoeff(result.rep, 115, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			break;
		case 116:
			NTL::SetCoeff(result.rep, 116, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 117:
			NTL::SetCoeff(result.rep, 117, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 118:
			NTL::SetCoeff(result.rep, 118, 1);
			NTL::SetCoeff(result.rep, 33, 1);
			break;
		case 119:
			NTL::SetCoeff(result.rep, 119, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			break;
		case 120:
			NTL::SetCoeff(result.rep, 120, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 121:
			NTL::SetCoeff(result.rep, 121, 1);
			NTL::SetCoeff(result.rep, 18, 1);
			break;
		case 122:
			NTL::SetCoeff(result.rep, 122, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 123:
			NTL::SetCoeff(result.rep, 123, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 124:
			NTL::SetCoeff(result.rep, 124, 1);
			NTL::SetCoeff(result.rep, 37, 1);
			break;
		case 125:
			NTL::SetCoeff(result.rep, 125, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			break;
		case 126:
			NTL::SetCoeff(result.rep, 126, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 127:
			NTL::SetCoeff(result.rep, 127, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 128:
			NTL::SetCoeff(result.rep, 128, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 129:
			NTL::SetCoeff(result.rep, 129, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			break;
		case 130:
			NTL::SetCoeff(result.rep, 130, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 131:
			NTL::SetCoeff(result.rep, 131, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 132:
			NTL::SetCoeff(result.rep, 132, 1);
			NTL::SetCoeff(result.rep, 29, 1);
			break;
		case 133:
			NTL::SetCoeff(result.rep, 133, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 134:
			NTL::SetCoeff(result.rep, 134, 1);
			NTL::SetCoeff(result.rep, 57, 1);
			break;
		case 135:
			NTL::SetCoeff(result.rep, 135, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			break;
		case 136:
			NTL::SetCoeff(result.rep, 136, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 137:
			NTL::SetCoeff(result.rep, 137, 1);
			NTL::SetCoeff(result.rep, 21, 1);
			break;
		case 138:
			NTL::SetCoeff(result.rep, 138, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 139:
			NTL::SetCoeff(result.rep, 139, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 140:
			NTL::SetCoeff(result.rep, 140, 1);
			NTL::SetCoeff(result.rep, 29, 1);
			break;
		case 141:
			NTL::SetCoeff(result.rep, 141, 1);
			NTL::SetCoeff(result.rep, 13, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 142:
			NTL::SetCoeff(result.rep, 142, 1);
			NTL::SetCoeff(result.rep, 21, 1);
			break;
		case 143:
			NTL::SetCoeff(result.rep, 143, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 144:
			NTL::SetCoeff(result.rep, 144, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 145:
			NTL::SetCoeff(result.rep, 145, 1);
			NTL::SetCoeff(result.rep, 52, 1);
			break;
		case 146:
			NTL::SetCoeff(result.rep, 146, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 147:
			NTL::SetCoeff(result.rep, 147, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 148:
			NTL::SetCoeff(result.rep, 148, 1);
			NTL::SetCoeff(result.rep, 27, 1);
			break;
		case 149:
			NTL::SetCoeff(result.rep, 149, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			break;
		case 150:
			NTL::SetCoeff(result.rep, 150, 1);
			NTL::SetCoeff(result.rep, 53, 1);
			break;
		case 151:
			NTL::SetCoeff(result.rep, 151, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 152:
			NTL::SetCoeff(result.rep, 152, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 153:
			NTL::SetCoeff(result.rep, 153, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 154:
			NTL::SetCoeff(result.rep, 154, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 155:
			NTL::SetCoeff(result.rep, 155, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			break;
		case 156:
			NTL::SetCoeff(result.rep, 156, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 157:
			NTL::SetCoeff(result.rep, 157, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 158:
			NTL::SetCoeff(result.rep, 158, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			break;
		case 159:
			NTL::SetCoeff(result.rep, 159, 1);
			NTL::SetCoeff(result.rep, 31, 1);
			break;
		case 160:
			NTL::SetCoeff(result.rep, 160, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 161:
			NTL::SetCoeff(result.rep, 161, 1);
			NTL::SetCoeff(result.rep, 18, 1);
			break;
		case 162:
			NTL::SetCoeff(result.rep, 162, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			break;
		case 163:
			NTL::SetCoeff(result.rep, 163, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 164:
			NTL::SetCoeff(result.rep, 164, 1);
			NTL::SetCoeff(result.rep, 12, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			break;
		case 165:
			NTL::SetCoeff(result.rep, 165, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 166:
			NTL::SetCoeff(result.rep, 166, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 167:
			NTL::SetCoeff(result.rep, 167, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			break;
		case 168:
			NTL::SetCoeff(result.rep, 168, 1);
			NTL::SetCoeff(result.rep, 16, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			break;
		case 169:
			NTL::SetCoeff(result.rep, 169, 1);
			NTL::SetCoeff(result.rep, 34, 1);
			break;
		case 170:
			NTL::SetCoeff(result.rep, 170, 1);
			NTL::SetCoeff(result.rep, 23, 1);
			break;
		case 171:
			NTL::SetCoeff(result.rep, 171, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 172:
			NTL::SetCoeff(result.rep, 172, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			break;
		case 173:
			NTL::SetCoeff(result.rep, 173, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 174:
			NTL::SetCoeff(result.rep, 174, 1);
			NTL::SetCoeff(result.rep, 13, 1);
			break;
		case 175:
			NTL::SetCoeff(result.rep, 175, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			break;
		case 176:
			NTL::SetCoeff(result.rep, 176, 1);
			NTL::SetCoeff(result.rep, 12, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			break;
		case 177:
			NTL::SetCoeff(result.rep, 177, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			break;
		case 178:
			NTL::SetCoeff(result.rep, 178, 1);
			NTL::SetCoeff(result.rep, 87, 1);
			break;
		case 179:
			NTL::SetCoeff(result.rep, 179, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 180:
			NTL::SetCoeff(result.rep, 180, 1);
			NTL::SetCoeff(result.rep, 12, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			break;
		case 181:
			NTL::SetCoeff(result.rep, 181, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 182:
			NTL::SetCoeff(result.rep, 182, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 183:
			NTL::SetCoeff(result.rep, 183, 1);
			NTL::SetCoeff(result.rep, 56, 1);
			break;
		case 184:
			NTL::SetCoeff(result.rep, 184, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			break;
		case 185:
			NTL::SetCoeff(result.rep, 185, 1);
			NTL::SetCoeff(result.rep, 24, 1);
			break;
		case 186:
			NTL::SetCoeff(result.rep, 186, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			break;
		case 187:
			NTL::SetCoeff(result.rep, 187, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			break;
		case 188:
			NTL::SetCoeff(result.rep, 188, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 189:
			NTL::SetCoeff(result.rep, 189, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 190:
			NTL::SetCoeff(result.rep, 190, 1);
			NTL::SetCoeff(result.rep, 13, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 191:
			NTL::SetCoeff(result.rep, 191, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			break;
		case 192:
			NTL::SetCoeff(result.rep, 192, 1);
			NTL::SetCoeff(result.rep, 15, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			break;
		case 193:
			NTL::SetCoeff(result.rep, 193, 1);
			NTL::SetCoeff(result.rep, 15, 1);
			break;
		case 194:
			NTL::SetCoeff(result.rep, 194, 1);
			NTL::SetCoeff(result.rep, 87, 1);
			break;
		case 195:
			NTL::SetCoeff(result.rep, 195, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 196:
			NTL::SetCoeff(result.rep, 196, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 197:
			NTL::SetCoeff(result.rep, 197, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 198:
			NTL::SetCoeff(result.rep, 198, 1);
			NTL::SetCoeff(result.rep, 65, 1);
			break;
		case 199:
			NTL::SetCoeff(result.rep, 199, 1);
			NTL::SetCoeff(result.rep, 34, 1);
			break;
		case 200:
			NTL::SetCoeff(result.rep, 200, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 201:
			NTL::SetCoeff(result.rep, 201, 1);
			NTL::SetCoeff(result.rep, 14, 1);
			break;
		case 202:
			NTL::SetCoeff(result.rep, 202, 1);
			NTL::SetCoeff(result.rep, 55, 1);
			break;
		case 203:
			NTL::SetCoeff(result.rep, 203, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 204:
			NTL::SetCoeff(result.rep, 204, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 205:
			NTL::SetCoeff(result.rep, 205, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 206:
			NTL::SetCoeff(result.rep, 206, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			break;
		case 207:
			NTL::SetCoeff(result.rep, 207, 1);
			NTL::SetCoeff(result.rep, 43, 1);
			break;
		case 208:
			NTL::SetCoeff(result.rep, 208, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 209:
			NTL::SetCoeff(result.rep, 209, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			break;
		case 210:
			NTL::SetCoeff(result.rep, 210, 1);
			NTL::SetCoeff(result.rep, 12, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 211:
			NTL::SetCoeff(result.rep, 211, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			break;
		case 212:
			NTL::SetCoeff(result.rep, 212, 1);
			NTL::SetCoeff(result.rep, 105, 1);
			break;
		case 213:
			NTL::SetCoeff(result.rep, 213, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 214:
			NTL::SetCoeff(result.rep, 214, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 215:
			NTL::SetCoeff(result.rep, 215, 1);
			NTL::SetCoeff(result.rep, 23, 1);
			break;
		case 216:
			NTL::SetCoeff(result.rep, 216, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 217:
			NTL::SetCoeff(result.rep, 217, 1);
			NTL::SetCoeff(result.rep, 45, 1);
			break;
		case 218:
			NTL::SetCoeff(result.rep, 218, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			break;
		case 219:
			NTL::SetCoeff(result.rep, 219, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 220:
			NTL::SetCoeff(result.rep, 220, 1);
			NTL::SetCoeff(result.rep, 12, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			break;
		case 221:
			NTL::SetCoeff(result.rep, 221, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 222:
			NTL::SetCoeff(result.rep, 222, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 223:
			NTL::SetCoeff(result.rep, 223, 1);
			NTL::SetCoeff(result.rep, 33, 1);
			break;
		case 224:
			NTL::SetCoeff(result.rep, 224, 1);
			NTL::SetCoeff(result.rep, 12, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 225:
			NTL::SetCoeff(result.rep, 225, 1);
			NTL::SetCoeff(result.rep, 32, 1);
			break;
		case 226:
			NTL::SetCoeff(result.rep, 226, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 227:
			NTL::SetCoeff(result.rep, 227, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			break;
		case 228:
			NTL::SetCoeff(result.rep, 228, 1);
			NTL::SetCoeff(result.rep, 12, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 229:
			NTL::SetCoeff(result.rep, 229, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 230:
			NTL::SetCoeff(result.rep, 230, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			break;
		case 231:
			NTL::SetCoeff(result.rep, 231, 1);
			NTL::SetCoeff(result.rep, 26, 1);
			break;
		case 232:
			NTL::SetCoeff(result.rep, 232, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			break;
		case 233:
			NTL::SetCoeff(result.rep, 233, 1);
			NTL::SetCoeff(result.rep, 74, 1);
			break;
		case 234:
			NTL::SetCoeff(result.rep, 234, 1);
			NTL::SetCoeff(result.rep, 31, 1);
			break;
		case 235:
			NTL::SetCoeff(result.rep, 235, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 236:
			NTL::SetCoeff(result.rep, 236, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			break;
		case 237:
			NTL::SetCoeff(result.rep, 237, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 238:
			NTL::SetCoeff(result.rep, 238, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 239:
			NTL::SetCoeff(result.rep, 239, 1);
			NTL::SetCoeff(result.rep, 36, 1);
			break;
		case 240:
			NTL::SetCoeff(result.rep, 240, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			break;
		case 241:
			NTL::SetCoeff(result.rep, 241, 1);
			NTL::SetCoeff(result.rep, 70, 1);
			break;
		case 242:
			NTL::SetCoeff(result.rep, 242, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 243:
			NTL::SetCoeff(result.rep, 243, 1);
			NTL::SetCoeff(result.rep, 8, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 244:
			NTL::SetCoeff(result.rep, 244, 1);
			NTL::SetCoeff(result.rep, 9, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 245:
			NTL::SetCoeff(result.rep, 245, 1);
			NTL::SetCoeff(result.rep, 6, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 246:
			NTL::SetCoeff(result.rep, 246, 1);
			NTL::SetCoeff(result.rep, 11, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 247:
			NTL::SetCoeff(result.rep, 247, 1);
			NTL::SetCoeff(result.rep, 82, 1);
			break;
		case 248:
			NTL::SetCoeff(result.rep, 248, 1);
			NTL::SetCoeff(result.rep, 15, 1);
			NTL::SetCoeff(result.rep, 14, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			break;
		case 249:
			NTL::SetCoeff(result.rep, 249, 1);
			NTL::SetCoeff(result.rep, 86, 1);
			break;
		case 250:
			NTL::SetCoeff(result.rep, 250, 1);
			NTL::SetCoeff(result.rep, 103, 1);
			break;
		case 251:
			NTL::SetCoeff(result.rep, 251, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 4, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 252:
			NTL::SetCoeff(result.rep, 252, 1);
			NTL::SetCoeff(result.rep, 67, 1);
			break;
		case 253:
			NTL::SetCoeff(result.rep, 253, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 3, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		case 254:
			NTL::SetCoeff(result.rep, 254, 1);
			NTL::SetCoeff(result.rep, 7, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			NTL::SetCoeff(result.rep, 1, 1);
			break;
		case 255:
			NTL::SetCoeff(result.rep, 255, 1);
			NTL::SetCoeff(result.rep, 52, 1);
			break;
		case 256:
			NTL::SetCoeff(result.rep, 256, 1);
			NTL::SetCoeff(result.rep, 10, 1);
			NTL::SetCoeff(result.rep, 5, 1);
			NTL::SetCoeff(result.rep, 2, 1);
			break;
		default:
			break;
	}
	return result;
}
