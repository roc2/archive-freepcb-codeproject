#ifndef _DLE_LINE_H /* [ */
#define _DLE_LINE_H

#include "DrawingElement.h"

// line segment with round end-caps
class CDLE_LINE : public CDLElement
{
protected:
	virtual void DrawHiliteSeg(CDrawInfo &di) 
		{ if( visible && dlist->m_vis[ orig_layer ] ) _Draw(di, true); }	// CPT.  Overrides default behavior, which is to do nothing.
	virtual void _Draw(CDrawInfo &di, bool bHiliteSegs);
	virtual int _IsHit(double x, double y, double &d);
	virtual int _GetBoundingRect(CRect &rect);
};

#endif /* !_DLE_LINE_H ] */
