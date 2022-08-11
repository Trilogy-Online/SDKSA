/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.Pickup;

import TrilogyOnline.SDK.Fundamental;
import TrilogyOnline.SDK.Placeable;

export namespace TrilogyOnline
{
	namespace API
	{
		class CPlayer;

		class CPickup : public CPlaceable
		{
		public:
			static constexpr auto Maximum = 100000u;

			enum class EType : UInt8
			{
				None,
				InShop,
				OnStreet,
				Once,
				OnceTimeout,
				OnceTimeoutSlow,
				Collectable,
				InShopOutOfStock,
				Money,
				MineInactive,
				MineArmed,
				NauticalMineInactive,
				NauticalMineArmed,
				FloatingPackage,
				FloatingPackageFloating,
				OnStreetSlow,
				AssetRevenue,
				PropertyLocked,
				PropertyForSale,
				MoneyDoesntdisappear,
				Snapshot,
				SecondPlayer,
				OnceForMission
			};

			class CState
			{
			public:
				virtual void OnStreamIn(CPickup& pickup, CPlayer& forPlayer) = 0;

				virtual void OnStreamOut(CPickup& pickup, CPlayer& forPlayer) = 0;

				virtual void OnCollected(CPickup& pickup, CPlayer& byPlayer) = 0;

#ifdef TRILOGY_ONLINE_CLIENT
				virtual void OnSyncingUserDataUpdated(CPickup& pickup, const UInt64 oldValue, const UInt64 newValue) = 0;
#endif
			};

			virtual void SetState(CState* const value) noexcept = 0;

			[[nodiscard]]
			virtual CState* GetState() const noexcept = 0;

			virtual void SetType(const EType value) = 0;

			[[nodiscard]]
			virtual EType GetType() const = 0;

			virtual void SetModelId(const UInt32 value) = 0;

			[[nodiscard]]
			virtual UInt32 GetModelId() const = 0;
		};
	}
}