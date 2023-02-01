// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	PREINIT,
	LOADING,
	READY,
	DEAD
};

DECLARE_LOG_CATEGORY_EXTERN(ArenaBattle, Log, All);

//로그 카테고리를 ArenaBattle로 고정하고 로그를 남길 때 추가로 발생한 함수 이름과 코드 라인을 함께 출력
//ABLOG_S : 코드가 들어있는 파일 이름과 함수, 그리고 라인 정보를 추가해 ArenaBattle 카테고리로 로그를 남김.
//ABLOG : ABLOG_S 정보에 형식 무자열로 추가 정보를 지정해 로그를 남긴다.

#define ABLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define ABLOG_S(Verbosity) UE_LOG(ArenaBattle, Verbosity, TEXT("%s"), *ABLOG_CALLINFO)
#define ABLOG(Verbosity, Format, ...) UE_LOG(ArenaBattle, Verbosity, TEXT("%s%s"), *ABLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
#define ABCHECK(Expr,...) {if(!(Expr)) {ABLOG(Error, TEXT("ASSERTION : %s"),TEXT("'"#Expr"'")); return __VA_ARGS__;}}
