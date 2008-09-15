//////////////////////////////////////////////////////////////////////////
//
// pgScript - PostgreSQL Tools
// RCS-ID:      $Id: pgsNegate.cpp,v 1.2 2008/08/10 17:45:36 pgunittest Exp $
// Copyright (C) 2002 - 2008, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
//////////////////////////////////////////////////////////////////////////


#include "pgAdmin3.h"
#include "pgscript/expressions/pgsNegate.h"

#include "pgscript/objects/pgsNumber.h"

pgsNegate::pgsNegate(const pgsExpression * left) :
	pgsOperation(left, 0)
{
	
}

pgsNegate::~pgsNegate()
{
	
}

pgsExpression * pgsNegate::clone() const
{
	return pnew pgsNegate(*this);
}

pgsNegate::pgsNegate(const pgsNegate & that) :
	pgsOperation(that)
{

}

pgsNegate & pgsNegate::operator =(const pgsNegate & that)
{
	if (this != &that)
	{
		pgsOperation::operator=(that);
	}
	return (*this);
}

wxString pgsNegate::value() const
{
	return wxString() << wxT("-") << m_left->value();
}

pgsOperand pgsNegate::eval(pgsVarMap & vars) const
{
	// Evaluate operands
	pgsOperand left(pnew pgsNumber(wxT("0"), pgsInt));
	pgsOperand right(m_left->eval(vars));
	
	// Return the result
	return (*left - *right);
}