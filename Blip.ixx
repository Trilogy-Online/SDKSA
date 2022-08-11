/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.Blip;

import TrilogyOnline.SDK.Fundamental;
import TrilogyOnline.SDK.Placeable;

export namespace TrilogyOnline
{
	namespace API
	{
		class CPlayer;

		class CBlip : public CPlaceable
		{
		public:
			static constexpr auto Maximum = 100000u;

			enum class ESprite : UInt8
			{
				None,
				White,
				Centre,
				MapHere,
				North,
				Airyard,
				AmmuGun,
				Barbers,
				BigSmoke,
				Boatyard,
				BurgerShot,
				Bulldozer,
				CatalinaPink,
				CesarViapando,
				Chicken,
				CJ,
				CRASH,
				Diner,
				EmmetGun,
				EnemyAttack,
				Fire,
				Girlfriend,
				Hostpital,
				LocoSyndicate,
				MaddDogg,
				MafiaCasino,
				MCStrap,
				ModGarage,
				OGLoc,
				Pizza,
				Police,
				PropertyGreen,
				PropertyRed,
				Race,
				Ryder,
				SaveGame,
				School,
				QuestionMark,
				Sweet,
				Tattoo,
				TheTruth,
				Waypoint,
				TorenoRanch,
				Triads,
				TriadsCasino,
				Tshirt,
				Woozie,
				Zero,
				Disco,
				Drink,
				Food,
				Truck,
				Cash,
				Flag,
				GYM,
				Impound,
				Light,
				Runway,
				GangBlue,
				GangPurple,
				GangYellow,
				GangN, // N?
				GangGreen,
				Spray
			};

			enum class EColor : UInt8
			{
				Red,
				Green,
				Blue,
				White,
				Yellow,
				RedCopy,
				BlueCopy,
				Threat,
				Destination
			};

			class CState
			{
			public:
				virtual void OnStreamIn(CBlip& blip, CPlayer& forPlayer) = 0;

				virtual void OnStreamOut(CBlip& blip, CPlayer& forPlayer) = 0;

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnSyncingUserDataUpdated(CBlip& blip, const UInt64 oldValue, const UInt64 newValue) = 0;
#endif
			};

			virtual void SetState(CState* const value) noexcept = 0;

			[[nodiscard]]
			virtual CState* GetState() const noexcept = 0;

			virtual void SetSprite(const ESprite value) = 0;

			[[nodiscard]]
			virtual ESprite GetSprite() const = 0;

			virtual void SetColor(const EColor value) = 0;

			[[nodiscard]]
			virtual EColor GetColor() const = 0;

			virtual void ToggleShortRange(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsShortRange() const = 0;

			virtual void SetScale(const UInt16 value) = 0;

			[[nodiscard]]
			virtual UInt16 GetScale() const = 0;
		};
	}
}