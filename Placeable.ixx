/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.Placeable;

import TrilogyOnline.SDK.Fundamental;
import TrilogyOnline.SDK.Vector;

export namespace TrilogyOnline
{
	namespace API
	{
		class CPlaceable
		{
		public:
			enum class EDerivedType : UInt8
			{
				Player,
				Blip,
				Checkpoint,
				Object,
				Pickup,
				Vehicle
			};

			virtual ~CPlaceable() noexcept = default;

			[[nodiscard]]
			virtual EDerivedType GetDerivedType() const noexcept = 0;

			virtual void SetUserData(void* const value) noexcept = 0;

			[[nodiscard]]
			virtual void* GetUserData() const noexcept = 0;

			virtual void SetPosition(const CVector3DFloat& value) = 0;

			[[nodiscard]]
			virtual CVector3DFloat GetPosition() const = 0;

			virtual void SetRotation(const CVector3DFloat& value) = 0;

			[[nodiscard]]
			virtual CVector3DFloat GetRotation() const = 0;

			virtual void SetHeading(const float value) = 0;

			[[nodiscard]]
			virtual float GetHeading() const = 0;

			virtual void SetStreamRadius(const float value) = 0;

			[[nodiscard]]
			virtual float GetStreamRadius() const = 0;

			[[nodiscard]]
			virtual UInt64 GetSyncingUserData() const = 0;

#ifdef TRILOGY_ONLINE_SERVER
			virtual void SetSyncingUserData(const UInt64 value) = 0;

			virtual void SetWorldId(const UInt64 value) = 0;

			virtual UInt64 GetWorldId() const = 0;
#endif
		};
	}
}