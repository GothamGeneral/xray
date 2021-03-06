//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc. and/or its licensors.  All 
// rights reserved.
//
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors, which is protected by U.S. and Canadian federal copyright 
// law and by international treaties.
//
// The Data is provided for use exclusively by You. You have the right 
// to use, modify, and incorporate this Data into other products for 
// purposes authorized by the Autodesk software license agreement, 
// without fee.
//
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the 
// following disclaimer, must be included in all copies of the 
// Software, in whole or in part, and all derivative works of 
// the Software, unless such copies or derivative works are solely 
// in the form of machine-executable object code generated by a 
// source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR 
// PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE, OR 
// TRADE PRACTICE. IN NO EVENT WILL AUTODESK AND/OR ITS LICENSORS 
// BE LIABLE FOR ANY LOST REVENUES, DATA, OR PROFITS, OR SPECIAL, 
// DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK 
// AND/OR ITS LICENSORS HAS BEEN ADVISED OF THE POSSIBILITY 
// OR PROBABILITY OF SUCH DAMAGES.
//
// ==========================================================================
//+

//	File Name: narrowPolyViewerCmd.h
//
//	Description:
//		Code to test drawing with multiple cameras in the same view.
//

#ifndef NARROWPOLYVIEWERCMD_H
#define NARROWPOLYVIEWERCMD_H

#include <maya/MDagPathArray.h>
#include <maya/MPxModelEditorCommand.h>

#include "narrowPolyViewer.h"

#define kInitFlag			"-in"
#define kInitFlagLong		"-initilize"

#define kResultsFlag		"-r"
#define kResultsFlagLong	"-results"

#define kClearFlag			"-cl"
#define kClearFlagLong		"-clear"

#define kToleranceFlag		"-tol"
#define kToleranceFlagLong	"-tolerance"

#define kViewCmdName		"narrowPolyViewer"

class MPx3dModelView;
class MObject;
class MDagPath;

class narrowPolyViewerCmd: public MPxModelEditorCommand
{
public:
	typedef MPxModelEditorCommand ParentClass;

						narrowPolyViewerCmd();
	virtual				~narrowPolyViewerCmd();

	static void*		creator();

	virtual MStatus		doEditFlags();

	virtual MStatus 	doQueryFlags();

	virtual MStatus 	appendSyntax();

protected:

	MStatus initTests(narrowPolyViewer &view);
	MStatus testResults(narrowPolyViewer &view);
	MStatus clearResults(narrowPolyViewer &view);
	MDagPathArray 		fCameraList;

private:
	static const char*  className() { return "narrowPolyViewerCmd"; }
};
#endif
