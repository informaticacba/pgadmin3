//////////////////////////////////////////////////////////////////////////
//
// pgScript - PostgreSQL Tools
// RCS-ID:      $Id: pgsDeclareRecordStmt.h,v 1.2 2008/08/10 17:45:36 pgunittest Exp $
// Copyright (C) 2002 - 2008, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
//////////////////////////////////////////////////////////////////////////


#ifndef PGSDECLARERECORDSTMT_H_
#define PGSDECLARERECORDSTMT_H_

#include "pgscript/pgScript.h"
#include "pgscript/statements/pgsStmt.h"

class pgsDeclareRecordStmt : public pgsStmt
{

private:

	const wxString m_rec;
	const wxArrayString m_columns;

public:

	pgsDeclareRecordStmt(const wxString & rec,
			const wxArrayString & columns, pgsThread * app = 0);

	virtual ~pgsDeclareRecordStmt();

	virtual void eval(pgsVarMap & vars) const;

private:

	pgsDeclareRecordStmt(const pgsDeclareRecordStmt & that);

	pgsDeclareRecordStmt & operator=(const pgsDeclareRecordStmt & that);

};

#endif /*PGSDECLARERECORDSTMT_H_*/