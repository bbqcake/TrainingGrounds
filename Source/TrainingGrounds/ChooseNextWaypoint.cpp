// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "TrainingGrounds.h"
#include "AIController.h"
#include "PatrollingGuard.h" // TODO REMOVE LATER
#include "BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// TODO protect against empty patrolRoutes

	// get the control points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;

	// Set Next WayPoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	// This gets the name of the blackboard key selector
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);


	//UE_LOG(LogTemp, Warning, TEXT("Waypoint index %i"), Index);
	// This is like clicking the success button in the BP
	return EBTNodeResult::Succeeded;
}


