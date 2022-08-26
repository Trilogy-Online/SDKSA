/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

#include <compare>
#include <cmath>
#include <utility>
#include <type_traits>
#include <math.h>

export module TrilogyOnline.SDK.Vector;

import TrilogyOnline.SDK.Fundamental;

export namespace TrilogyOnline
{
	namespace API
	{
		template<class ComponentType, NativeUInt Dimension>
		struct CVectorStore
		{
			ComponentType Components[Dimension]{ };
		};

		template<class ComponentType>
		struct CVectorStore<ComponentType, 1>
		{
			ComponentType Components[1]{ };

			constexpr auto& X() noexcept
			{
				return Components[0];
			}
			
			constexpr auto& X() const noexcept
			{
				return Components[0];
			}
		};

		template<class ComponentType>
		struct CVectorStore<ComponentType, 2>
		{
			ComponentType Components[2]{ };

			constexpr auto& X() noexcept
			{
				return Components[0];
			}

			constexpr auto& X() const noexcept
			{
				return Components[0];
			}

			constexpr auto& Y() noexcept
			{
				return Components[1];
			}

			constexpr auto& Y() const noexcept
			{
				return Components[1];
			}
		};

		template<class ComponentType>
		struct CVectorStore<ComponentType, 3>
		{
			ComponentType Components[3]{ };

			constexpr auto& X() noexcept
			{
				return Components[0];
			}

			constexpr auto& X() const noexcept
			{
				return Components[0];
			}

			constexpr auto& Y() noexcept
			{
				return Components[1];
			}

			constexpr auto& Y() const noexcept
			{
				return Components[1];
			}

			constexpr auto& Z() noexcept
			{
				return Components[2];
			}

			constexpr auto& Z() const noexcept
			{
				return Components[2];
			}
		};

		template<class ComponentType>
		struct CVectorStore<ComponentType, 4>
		{
			ComponentType Components[4]{ };

			constexpr auto& X() noexcept
			{
				return Components[0];
			}

			constexpr auto& X() const noexcept
			{
				return Components[0];
			}

			constexpr auto& Y() noexcept
			{
				return Components[1];
			}

			constexpr auto& Y() const noexcept
			{
				return Components[1];
			}

			constexpr auto& Z() noexcept
			{
				return Components[2];
			}

			constexpr auto& Z() const noexcept
			{
				return Components[2];
			}

			constexpr auto& W() noexcept
			{
				return Components[3];
			}

			constexpr auto& W() const noexcept
			{
				return Components[3];
			}
		};

		template<class ComponentType, NativeUInt Dimension>
			requires (Dimension > 0)
		class CVector;

		template<class Type>
		constexpr auto IsVector = false;

		template<class ComponentType, NativeUInt Dimension>
		constexpr auto IsVector<CVector<ComponentType, Dimension>> = true;

		template<class ComponentType, NativeUInt Dimension>
			requires (Dimension > 0)
		class CVector : public CVectorStore<ComponentType, Dimension>
		{
		private:
			using Base = CVectorStore<ComponentType, Dimension>;

		public:
			using CVectorStore<ComponentType, Dimension>::Components;

		private:
			static constexpr auto DimensionIndicesSequence{ std::make_index_sequence<Dimension>{ } };

			template<class ThatComponentType, NativeUInt... Indices>
			constexpr CVector(const CVector<ThatComponentType, Dimension>& that, std::index_sequence<Indices...>)
				noexcept(std::is_nothrow_constructible_v<Base, decltype(that.Components[Indices])...>) :
				Base{ that.Components[Indices]... } { }

			template<class ThatComponentType, NativeUInt... Indices>
			constexpr CVector(CVector<ThatComponentType, Dimension>&& that, std::index_sequence<Indices...>)
				noexcept(std::is_nothrow_constructible_v<Base, decltype(std::move(that.Components[Indices]))...>) :
				Base{ std::move(that.Components[Indices])... } { }

			template<class CastType, NativeUInt... Indices>
			constexpr auto StaticCast(std::index_sequence<Indices...>) const
				noexcept(noexcept(CVector<CastType, Dimension>{ static_cast<CastType>(Components[Indices])... }))
			{
				return CVector<CastType, Dimension>{ static_cast<CastType>(Components[Indices])... };
			}

			template<NativeUInt... Indices>
			constexpr auto Square(std::index_sequence<Indices...>) const
				noexcept(noexcept(((Components[Indices] * Components[Indices]) + ...)))
			{
				return ((Components[Indices] * Components[Indices]) + ...);
			}

			template<NativeUInt... Indices>
			constexpr auto EqualTo(const CVector& that, std::index_sequence<Indices...>) const
				noexcept(noexcept(((Components[Indices] == that.Components[Indices]) && ...)))
			{
				return ((Components[Indices] == that.Components[Indices]) && ...);
			}

			template<NativeUInt... Indices>
			constexpr auto NotEqualTo(const CVector& that, std::index_sequence<Indices...>) const
				noexcept(noexcept(((Components[Indices] != that.Components[Indices]) || ...)))
			{
				return ((Components[Indices] != that.Components[Indices]) || ...);
			}

			template<NativeUInt... Indices>
			constexpr void AdditionAssignment(const CVector& that, std::index_sequence<Indices...>)
				noexcept(noexcept(((Components[Indices] += that.Components[Indices]), ...)))
			{
				((Components[Indices] += that.Components[Indices]), ...);
			}

			template<NativeUInt... Indices>
			constexpr void SubtractionAssignment(const CVector& that, std::index_sequence<Indices...>)
				noexcept(noexcept(((Components[Indices] -= that.Components[Indices]), ...)))
			{
				((Components[Indices] -= that.Components[Indices]), ...);
			}

			template<NativeUInt... Indices>
			constexpr void MultiplicationAssignment(const ComponentType& that, std::index_sequence<Indices...>)
				noexcept(noexcept(((Components[Indices] *= that), ...)))
			{
				((Components[Indices] *= that), ...);
			}

			template<NativeUInt... Indices>
			constexpr void DivisionAssignment(const ComponentType& that, std::index_sequence<Indices...>)
				noexcept(noexcept(((Components[Indices] /= that), ...)))
			{
				((Components[Indices] /= that), ...);
			}

			template<NativeUInt... Indices>
			constexpr auto Addition(const CVector& that, std::index_sequence<Indices...>) const
				noexcept(noexcept(CVector{ (Components[Indices] + that.Components[Indices])... }))
			{
				return CVector{ (Components[Indices] + that.Components[Indices])... };
			}

			template<NativeUInt... Indices>
			constexpr auto Subtraction(const CVector& that, std::index_sequence<Indices...>) const
				noexcept(noexcept(CVector{ (Components[Indices] - that.Components[Indices])... }))
			{
				return CVector{ (Components[Indices] - that.Components[Indices])... };
			}

			template<NativeUInt... Indices>
			constexpr auto Multiplication(const CVector& that, std::index_sequence<Indices...>) const
				noexcept(noexcept(((Components[Indices] * that.Components[Indices]) + ...)))
			{
				return ((Components[Indices] * that.Components[Indices]) + ...);
			}

			template<NativeUInt... Indices>
			constexpr auto Multiplication(const ComponentType& that, std::index_sequence<Indices...>) const
				noexcept(noexcept(CVector{ (Components[Indices] * that)... }))
			{
				return CVector{ (Components[Indices] * that)... };
			}

			template<NativeUInt... Indices>
			constexpr auto Division(const ComponentType& that, std::index_sequence<Indices...>) const
				noexcept(noexcept(CVector{ (Components[Indices] / that)... }))
			{
				return CVector{ (Components[Indices] / that)... };
			}

		public:
			constexpr CVector() noexcept(std::is_nothrow_constructible_v<Base>) = default;

			template<class ArgumentType, class... ArgumentTypes>
				requires (!IsVector<std::remove_cvref_t<ArgumentType>>)
			constexpr CVector(ArgumentType&& argument, ArgumentTypes&&... arguments)
				noexcept(std::is_nothrow_constructible_v<Base, ArgumentType&&> && (std::is_nothrow_constructible_v<Base, ArgumentTypes&&> && ...)) :
				Base{ std::forward<ArgumentType>(argument), std::forward<ArgumentTypes>(arguments)... } { }

			template<class ThatComponentType>
				requires (std::is_constructible_v<ComponentType, ThatComponentType>)
			constexpr CVector(const CVector<ThatComponentType, Dimension>& that)
				noexcept(std::is_nothrow_constructible_v<CVector, decltype(that), decltype(DimensionIndicesSequence)>) :
				CVector{ that, DimensionIndicesSequence } { }

			template<class ThatComponentType>
				requires (std::is_constructible_v<ComponentType, ThatComponentType>)
			constexpr CVector(CVector<ThatComponentType, Dimension>&& that)
				noexcept(std::is_nothrow_constructible_v<CVector, decltype(std::move(that)), decltype(DimensionIndicesSequence)>) :
				CVector{ std::move(that), DimensionIndicesSequence } { }
			
			template<class CastType>
			[[nodiscard]]
			constexpr auto StaticCast() const
				noexcept(noexcept(StaticCast<CastType>(DimensionIndicesSequence)))
			{
				return StaticCast<CastType>(DimensionIndicesSequence);
			}

			[[nodiscard]]
			constexpr auto Square() const
				noexcept(noexcept(Square(DimensionIndicesSequence)))
			{
				return Square(DimensionIndicesSequence);
			}

			[[nodiscard]]
			auto Length() const
				noexcept(noexcept(std::sqrt(Square())))
			{
				return std::sqrt(Square());
			}

			[[nodiscard]]
			constexpr auto operator<=>(const CVector& that) const
				noexcept(noexcept(Square() <=> that.Square()))
			{
				return Square() <=> that.Square();
			}

			[[nodiscard]]
			constexpr auto operator==(const CVector& that) const
				noexcept(noexcept(EqualTo(that, DimensionIndicesSequence)))
			{
				return EqualTo(that, DimensionIndicesSequence);
			}

			[[nodiscard]]
			constexpr auto operator!=(const CVector& that) const
				noexcept(noexcept(NotEqualTo(that, DimensionIndicesSequence)))
			{
				return NotEqualTo(that, DimensionIndicesSequence);
			}

			[[nodiscard]]
			constexpr auto& operator[](const NativeUInt index) noexcept
			{
				return Components[index];
			}

			[[nodiscard]]
			constexpr auto& operator[](const NativeUInt index) const noexcept
			{
				return Components[index];
			}

			constexpr auto& operator+=(const CVector& that)
				noexcept(noexcept(AdditionAssignment(that, DimensionIndicesSequence)))
			{
				AdditionAssignment(that, DimensionIndicesSequence);
				return *this;
			}

			constexpr auto& operator-=(const CVector& that)
				noexcept(noexcept(SubtractionAssignment(that, DimensionIndicesSequence)))
			{
				SubtractionAssignment(that, DimensionIndicesSequence);
				return *this;
			}

			constexpr auto& operator*=(const ComponentType& that)
				noexcept(noexcept(MultiplicationAssignment(that, DimensionIndicesSequence)))
			{
				MultiplicationAssignment(that, DimensionIndicesSequence);
				return *this;
			}

			constexpr auto& operator/=(const ComponentType& that)
				noexcept(noexcept(DivisionAssignment(that, DimensionIndicesSequence)))
			{
				DivisionAssignment(that, DimensionIndicesSequence);
				return *this;
			}

			[[nodiscard]]
			constexpr CVector operator+(const CVector& that) const
				noexcept(noexcept(Addition(that, DimensionIndicesSequence)))
			{
				return Addition(that, DimensionIndicesSequence);
			}

			[[nodiscard]]
			constexpr CVector operator-(const CVector& that) const
				noexcept(noexcept(Subtraction(that, DimensionIndicesSequence)))
			{
				return Subtraction(that, DimensionIndicesSequence);
			}

			[[nodiscard]]
			constexpr CVector operator*(const CVector& that) const
				noexcept(noexcept(Multiplication(that, DimensionIndicesSequence)))
			{
				return Multiplication(that, DimensionIndicesSequence);
			}

			[[nodiscard]]
			constexpr CVector operator*(const ComponentType& that) const
				noexcept(noexcept(Multiplication(that, DimensionIndicesSequence)))
			{
				return Multiplication(that, DimensionIndicesSequence);
			}

			[[nodiscard]]
			constexpr CVector operator/(const ComponentType& that) const
				noexcept(noexcept(Division(that, DimensionIndicesSequence)))
			{
				return Division(that, DimensionIndicesSequence);
			}
		};

		template<class ComponentType>
		using CVector1D = CVector<ComponentType, 1>;

		using CVector1DInt8 = CVector1D<Int8>;
		using CVector1DUInt8 = CVector1D<UInt8>;

		using CVector1DInt16 = CVector1D<Int16>;
		using CVector1DUInt16 = CVector1D<UInt16>;

		using CVector1DInt32 = CVector1D<Int32>;
		using CVector1DUInt32 = CVector1D<UInt32>;

		using CVector1DInt64 = CVector1D<Int64>;
		using CVector1DUInt64 = CVector1D<UInt64>;

		using CVector1DNativeInt = CVector1D<NativeInt>;
		using CVector1DNativeUInt = CVector1D<NativeUInt>;

		using CVector1DFloat = CVector1D<float>;

		using CVector1DDouble = CVector1D<double>;
		using CVector1DLongDouble = CVector1D<long double>;

		template<class ComponentType>
		using CVector2D = CVector<ComponentType, 2>;

		using CVector2DInt8 = CVector2D<Int8>;
		using CVector2DUInt8 = CVector2D<UInt8>;

		using CVector2DInt16 = CVector2D<Int16>;
		using CVector2DUInt16 = CVector2D<UInt16>;

		using CVector2DInt32 = CVector2D<Int32>;
		using CVector2DUInt32 = CVector2D<UInt32>;

		using CVector2DInt64 = CVector2D<Int64>;
		using CVector2DUInt64 = CVector2D<UInt64>;

		using CVector2DNativeInt = CVector2D<NativeInt>;
		using CVector2DNativeUInt = CVector2D<NativeUInt>;

		using CVector2DFloat = CVector2D<float>;

		using CVector2DDouble = CVector2D<double>;
		using CVector2DLongDouble = CVector2D<long double>;

		template<class ComponentType>
		using CVector3D = CVector<ComponentType, 3>;

		using CVector3DInt8 = CVector3D<Int8>;
		using CVector3DUInt8 = CVector3D<UInt8>;

		using CVector3DInt16 = CVector3D<Int16>;
		using CVector3DUInt16 = CVector3D<UInt16>;

		using CVector3DInt32 = CVector3D<Int32>;
		using CVector3DUInt32 = CVector3D<UInt32>;

		using CVector3DInt64 = CVector3D<Int64>;
		using CVector3DUInt64 = CVector3D<UInt64>;

		using CVector3DNativeInt = CVector3D<NativeInt>;
		using CVector3DNativeUInt = CVector3D<NativeUInt>;

		using CVector3DFloat = CVector3D<float>;

		using CVector3DDouble = CVector3D<double>;
		using CVector3DLongDouble = CVector3D<long double>;
	}
}