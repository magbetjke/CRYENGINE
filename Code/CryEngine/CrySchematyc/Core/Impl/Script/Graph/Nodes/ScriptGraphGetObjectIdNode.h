// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <Schematyc/Runtime/RuntimeGraph.h>
#include <Schematyc/Utils/GUID.h>

#include "Script/Graph/ScriptGraphNodeModel.h"

namespace Schematyc
{
class CScriptGraphGetObjectIdNode : public CScriptGraphNodeModel
{
private:

	struct EOutputIdx
	{
		enum : uint32
		{
			Value = 0
		};
	};

public:

	CScriptGraphGetObjectIdNode();

	// CScriptGraphNodeModel
	virtual SGUID GetTypeGUID() const override;
	virtual void  CreateLayout(CScriptGraphNodeLayout& layout) override;
	virtual void  Compile(SCompilerContext& context, IGraphNodeCompiler& compiler) const override;
	// ~CScriptGraphNodeModel

	static void Register(CScriptGraphNodeFactory& factory);

private:

	static SRuntimeResult Execute(SRuntimeContext& context, const SRuntimeActivationParams& activationParams);

public:

	static const SGUID ms_typeGUID;
};
}
