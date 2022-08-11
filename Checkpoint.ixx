/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.Checkpoint;

import TrilogyOnline.SDK.Fundamental;
import TrilogyOnline.SDK.Vector;
import TrilogyOnline.SDK.Placeable;

export namespace TrilogyOnline
{
	namespace API
	{
		class CPlayer;

		class CCheckpoint : public CPlaceable
		{
		public:
			static constexpr auto Maximum = 100000u;

			enum class EType : UInt8
			{
				Normal,
				Finish,
				Nothing,
				AirNormal,
				AirFinish,
				AirRotatesAndStops,
				AirIncreasesAndDecreasesAndDisappears,
				AirSwingsDownAndUp1,
				AirSwingsDownAndUp2
			};

			class CState
			{
			public:
				virtual void OnStreamIn(CCheckpoint& checkpoint, CPlayer& forPlayer) = 0;

				virtual void OnStreamOut(CCheckpoint& checkpoint, CPlayer& forPlayer) = 0;

				virtual void OnPlayerEntered(CCheckpoint& checkpoint, CPlayer& player) = 0;

				virtual void OnPlayerLeft(CCheckpoint& checkpoint, CPlayer& player) = 0;

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnSyncingUserDataUpdated(CCheckpoint& checkpoint, const UInt64 oldValue, const UInt64 newValue) = 0;
#endif
			};

			virtual void SetState(CState* const value) noexcept = 0;

			[[nodiscard]]
			virtual CState* GetState() const noexcept = 0;

			virtual void SetType(const EType value) = 0;

			[[nodiscard]]
			virtual EType GetType() const = 0;

			virtual void SetNextPosition(const CVector3DFloat& value) = 0;

			[[nodiscard]]
			virtual CVector3DFloat GetNextPosition() const = 0;

			virtual void SetRadius(const float value) = 0;

			[[nodiscard]]
			virtual float GetRadius() const = 0;

			virtual void SetColor(const UInt32 value) = 0;

			[[nodiscard]]
			virtual UInt32 GetColor() const = 0;

			virtual void SetPulsePeriod(const UInt16 value) = 0;

			[[nodiscard]]
			virtual UInt16 GetPulsePeriod() const = 0;

			virtual void SetPulseFraction(const float value) = 0;

			[[nodiscard]]
			virtual float GetPulseFraction() const = 0;

			virtual void SetRotateRate(const UInt16 value) = 0;

			[[nodiscard]]
			virtual UInt16 GetRotateRate() const = 0;
		};
	}
}